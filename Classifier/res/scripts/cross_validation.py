from sklearn.model_selection import cross_val_score

def cross_validate_model(model, X, y, cv=5):
    """
    Perform cross-validation evaluation on the model.

    Parameters:
    model : estimator object
        The machine learning model to be evaluated.
    X : DataFrame or ndarray, shape (n_samples, n_features)
        Feature data.
    y : Series or ndarray, shape (n_samples,)
        Label data.
    cv : int, optional, default=5
        Number of cross-validation folds.

    Returns:
    scores : array of float, shape (cv,)
        Scores for each cross-validation fold.
    """
    scores = cross_val_score(model, X, y, cv=cv)
    return scores
