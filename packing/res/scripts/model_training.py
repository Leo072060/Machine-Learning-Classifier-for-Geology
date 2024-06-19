def train_model(model, X_train, y_train):
    """
    训练给定的模型。

    参数:
    model : estimator object
        需要训练的机器学习模型。
    X_train : DataFrame or ndarray, shape (n_samples, n_features)
        训练特征数据。
    y_train : Series or ndarray, shape (n_samples,)
        训练标签数据。

    返回:
    model : estimator object
        训练后的模型。
    """
    model.fit(X_train, y_train)
    return model


