import itertools
import pandas as pd

def generate_feature_combinations(X, selected_labels, max_num_combinations, min_num_combinations=1):
    '''
    Generates different feature combinations of X, with the number of features in each combination 
    between min_num_combinations and max_num_combinations. Each returned combination is a DataFrame, 
    retaining the structure of the original DataFrame. Specific labels can be selected for combination.

    Parameters:
    X : DataFrame
        DataFrame containing all features.
    max_num_combinations : int
        The maximum number of features to be included in each combination.
    min_num_combinations : int, optional, default=1
        The minimum number of features to be included in each combination.
    selected_labels : list of str, optional, default=None
        Specific labels to be included in the combinations.

    Returns:
    combinations : list of DataFrame
        Each DataFrame contains a specific combination of features.
    '''
    combinations = []
    columns = X.columns

    # Check if all selected labels are present in the DataFrame columns
    for label in selected_labels:
        if label not in columns:
            print(f"Error: The selected label '{label}' is not found in the DataFrame columns.")
            return None

    if selected_labels:
        columns = [col for col in X.columns if col in selected_labels]

    for i in range(min_num_combinations, max_num_combinations + 1):
        comb = itertools.combinations(columns, i)
        for c in comb:
            combinations.append(X[list(c)])
    
    return combinations
