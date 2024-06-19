import numpy as np
from imblearn.under_sampling import TomekLinks
from sklearn.preprocessing import StandardScaler
import pandas as pd

chondrite_values = {
    "La": 0.24, "Ce": 0.61, "Pr": 0.1, "Nd": 0.47, "Sm": 0.15, "Eu": 0.06,
    "Gd": 0.21, "Tb": 0.04, "Dy": 0.25, "Ho": 0.06, "Er": 0.17, "Tm": 0.03,
    "Yb": 0.17, "Lu": 0.03
}

def ensure_numeric(X):
    """
    Ensure only numeric columns are retained.

    Parameters:
    X : DataFrame
        Original feature data.

    Returns:
    X_numeric : DataFrame
        DataFrame with only numeric columns.
    """
    return X.select_dtypes(include=[np.number])

def remove_na_rows(X, y):
    """
    Remove rows with missing values.

    Parameters:
    X : DataFrame
        Feature data with possible NaNs.
    y : Series
        Corresponding labels.

    Returns:
    X_clean : DataFrame
        DataFrame with rows containing NaNs removed.
    y_clean : Series
        Corresponding labels with rows containing NaNs removed.
    """
    valid_indices = ~X.isna().any(axis=1)
    return X[valid_indices], y[valid_indices]

def log_transform(X):
    """
    Apply log transformation to the data to handle skewness, keeping negative values.

    Parameters:
    X : DataFrame
        Feature data to be log-transformed.

    Returns:
    X_log : DataFrame
        Log-transformed feature data.
    """
    X_log = X.copy()
    positive_mask = X > 0
    X_log[positive_mask] = np.log10(X[positive_mask] + 1e-9)
    return X_log

def apply_tomek_links(X, y):
    """
    Apply Tomek Links under-sampling to balance the dataset.

    Parameters:
    X : DataFrame or ndarray
        Feature data.
    y : Series or ndarray
        Corresponding labels.

    Returns:
    X_resampled : ndarray
        Resampled feature data.
    y_resampled : ndarray
        Resampled labels.
    """
    tl = TomekLinks()
    return tl.fit_resample(X, y)

def standardize_data(X):
    """
    Standardize the data to have mean 0 and variance 1.

    Parameters:
    X : DataFrame or ndarray
        Feature data to be standardized.

    Returns:
    X_standardized : ndarray
        Standardized feature data.
    scaler : StandardScaler
        Fitted scaler object.
    """
    scaler = StandardScaler().fit(X)
    return scaler.transform(X), scaler

def chondrite_normalize(X):
    """
    Apply chondrite normalization to the data if specified elements are present.

    Parameters:
    X : DataFrame
        Feature data to be normalized.

    Returns:
    X_normalized : DataFrame
        Chondrite-normalized feature data.
    """
    elements_to_normalize = chondrite_values.keys()
    if any(elem in X.columns for elem in elements_to_normalize):
        for element in elements_to_normalize:
            if element in X.columns:
                X[element] = X[element] / chondrite_values[element]
    return X

def preprocess_data(X, y):
    """
    Preprocess the data by combining the above steps.

    Parameters:
    X : DataFrame
        Original feature data.
    y : Series
        Original labels.

    Returns:
    X_preprocessed : DataFrame
        Preprocessed feature data with column names preserved.
    y_preprocessed : Series
        Preprocessed labels.
    """
    X_numeric = ensure_numeric(X)
    X_clean, y_clean = remove_na_rows(X_numeric, y)
    X_log = log_transform(X_clean)
    X_normalized = chondrite_normalize(X_log)
    X_resampled, y_resampled = apply_tomek_links(X_normalized, y_clean)
    X_standardized, _ = standardize_data(X_resampled)
    X_preprocessed = pd.DataFrame(X_standardized, columns=X_numeric.columns)
    return X_preprocessed, y_resampled
