import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report
import matplotlib.pyplot as plt

def data_analysis_with_rf(file_path):
    """
    Perform data analysis with Random Forest on the given Excel file.

    Parameters:
    file_path : str
        The path to the Excel file.

    Returns:
    None
    """
    # Load and prepare data
    data = pd.read_excel(file_path)
    y = data.iloc[:, 0]  # The first column is the type (label)
    X = data.iloc[:, 1:]  # The remaining columns are features

    # Check and convert data types
    X = X.apply(pd.to_numeric, errors='coerce')  # Convert non-convertible values to NaN
    X = X.fillna(0)  # Fill NaNs with zeros

    # Split the dataset
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

    # Train Random Forest model
    rf_clf = RandomForestClassifier(n_estimators=100, random_state=42)
    rf_clf.fit(X_train, y_train)

    # Make predictions
    y_pred = rf_clf.predict(X_test)

    # Calculate accuracy
    accuracy = accuracy_score(y_test, y_pred)
    print(f'Accuracy: {accuracy:.2f}')
    print(classification_report(y_test, y_pred))

    # Get feature importance
    feature_importances = rf_clf.feature_importances_
    feature_names = X.columns
    feature_importance_df = pd.DataFrame({
        'Feature': feature_names,
        'Importance': feature_importances
    }).sort_values(by='Importance', ascending=False)

    # Print feature importance
    print(feature_importance_df)

    # Visualize feature importance
    plt.figure(figsize=(10, 6))
    plt.barh(feature_importance_df['Feature'], feature_importance_df['Importance'])
    plt.xlabel('Feature Importance')
    plt.ylabel('Features')
    plt.title('Feature Importance in Random Forest Classifier')
    plt.gca().invert_yaxis()
    plt.show()


