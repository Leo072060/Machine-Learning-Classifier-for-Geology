from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.neighbors import KNeighborsClassifier
import xgboost as xgb

def get_svm_model():
    """
    Returns a configured SVM model
    """
    svm = SVC(kernel='rbf',
              C=2,
              gamma=1,
              cache_size=1000,
              class_weight='balanced',
              probability=True)
    return svm

def get_rf_model():
    """
    Returns a configured Random Forest model
    """
    rf = RandomForestClassifier(n_estimators=400,
                                min_samples_split=4,
                                max_depth=20,
                                min_samples_leaf=1,
                                max_features=3,
                                random_state=42,
                                class_weight='balanced',
                                oob_score=True)
    return rf

def get_mlp_model():
    """
    Returns a configured MLP model
    """
    mlp = MLPClassifier(hidden_layer_sizes=(100, 200, 100),
                        random_state=42,
                        max_iter=500,
                        solver='adam',
                        activation='tanh')
    return mlp

def get_xgboost_model():
    """
    Returns a configured XGBoost model
    """
    xgb_model = xgb.XGBClassifier(objective='multi:softmax',
                                  num_class=3,  # Adjust the number of classes as per your dataset
                                  learning_rate=0.1,
                                  max_depth=6,
                                  n_estimators=100,
                                  subsample=0.8,
                                  colsample_bytree=0.8,
                                  random_state=42)
    return xgb_model

def get_knn_model():
    """
    Returns a configured KNN model
    """
    knn = KNeighborsClassifier(n_neighbors=5,  # Number of neighbors
                               weights='uniform',  # Weight function used in prediction
                               algorithm='auto',  # Algorithm used to compute the nearest neighbors
                               leaf_size=30,  # Leaf size passed to BallTree or KDTree
                               p=2,  # Power parameter for the Minkowski metric
                               metric='minkowski')  # Distance metric to use
    return knn
