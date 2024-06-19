print('-------------------------------------Python----------------------------------------------')

import argparse
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from colorama import Fore, Style
import os
import datetime
import models
from feature_combinations import generate_feature_combinations
from data_preprocessing import preprocess_data
from model_training import train_model
from evaluation import evaluate_model, plot_confusion_matrix, plot_radar_chart
from cross_validation import cross_validate_model
from data_analysis_with_rf import data_analysis_with_rf

def evaluate_and_report(training_data_path, report_save_path, 
                        model_names,
                        selected_labels, 
                        cv_folds,
                        maximal_number_of_combinations,
                        minimal_number_of_combinations,
                        ):
    # Load data
    data = pd.read_csv(training_data_path)
    X = data.iloc[:, 1:]  
    y = data.iloc[:, 0]   

    # Generate feature combinations for model evaluation through exhaustive method
    combinations = generate_feature_combinations(X, selected_labels=selected_labels, max_num_combinations=maximal_number_of_combinations, min_num_combinations=minimal_number_of_combinations)

    results = []

    # Train and evaluate models for different feature combinations
    for combo in combinations:

        # Data preprocessing
        X_preprocessed, y_preprocessed = preprocess_data(combo, y)
        
        # Skip combination if preprocessed data is below a certain threshold
        if len(X_preprocessed) < 300:  # This threshold can be adjusted
            print(f"Combination {combo.columns.tolist()} skipped due to insufficient data.")
            continue
            
        # Split dataset into training and testing sets
        X_train, X_test, y_train, y_test = train_test_split(X_preprocessed, y_preprocessed, test_size=0.2, random_state=42)
        
        print('Processing:', f"Combination: {combo.columns.tolist()}")

        for model_name in model_names:
            # Select pre-configured model
            model = getattr(models, f"get_{model_name}_model")()

            # Cross-validation evaluation
            model_scores = cross_validate_model(model, X_train, y_train, cv=cv_folds)
            model_scores_mean = np.mean(model_scores)
            
            # Train the model
            model_trained = train_model(model, X_train, y_train)

            # Evaluate the model
            report_dict, report_str, conf_matrix = evaluate_model(model_trained, X_test, y_test)
            report_str = classification_report(y_test, model_trained.predict(X_test))

            # Record results
            results.append((combo, model_name, model_scores_mean, report_dict, report_str, conf_matrix))

    # Generate report

    # Create a new markdown document
    now = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    folder_name = report_save_path + f"/result_{now}"
    img_folder_name = os.path.join(folder_name, "img")
    os.makedirs(img_folder_name, exist_ok=True)
    md_file_path = os.path.join(folder_name, 'results.md')

    with open(md_file_path, 'w', encoding='utf-8') as f:
        for result in results:
            combo, model_name, scores_mean, report_dict, report_str, conf_matrix = result

            # Select color based on score range
            if scores_mean >= 0.9:
                color = 'green'
            elif scores_mean >= 0.7:
                color = 'yellow'
            else:
                color = 'red'

            f.write(f"# Combination: {combo.columns.tolist()}\n")
            f.write(f"## Model: {model_name}\n")
            f.write(f"**Cross-validation mean score:** <span style='color:{color}'>{scores_mean:.4f}</span>\n")
            f.write("**Classification report:**\n")
            f.write("```\n")
            f.write(report_str)
            f.write("```\n\n")
            
            # Save confusion matrix image
            title = f"Combinations_{'_'.join(combo.columns.tolist())}_{model_name}"
            img_path = os.path.join(img_folder_name, f"{title}_confusion_matrix.png")
            plot_confusion_matrix(conf_matrix, title=title, class_names=y_test.unique(), file_path=img_path)
            
            # Insert confusion matrix image path into markdown file
            f.write(f"**Confusion matrix image:**\n\n")
            img_path_md = os.path.join('img', f"{title}_confusion_matrix.png")
            f.write(f"![{title}]({img_path_md})\n\n")

    print(f"Results saved to {folder_name}")




if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Process some input parameters.")
    parser.add_argument("--training_data_path", type=str, required=True, help="Path to the training data CSV file")
    parser.add_argument("--report_save_path", type=str, required=True, help="Path to save the report")
    parser.add_argument("--algorithm_names", type=str, required=True, help="Comma-separated list of algorithms")
    parser.add_argument("--features", type=str, required=True, help="Comma-separated list of selected features")
    parser.add_argument("--number_of_folds", type=int, required=True, help="Number of folds for cross-validation")
    parser.add_argument("--maximal_number_of_combinations", type=int, required=True, help="Maximum number of feature combinations")
    parser.add_argument("--minimal_number_of_combinations", type=int, required=True, help="Minimum number of feature combinations")
    
    args = parser.parse_args()

    evaluate_and_report(args.training_data_path, args.report_save_path, args.algorithm_names.split(','), args.features.split(','), args.number_of_folds, args.maximal_number_of_combinations, args.minimal_number_of_combinations)