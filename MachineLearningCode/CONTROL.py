from main import evaluate_and_report
from data_analysis_with_rf import data_analysis_with_rf

#                                                                    ||||
#                                                                    ||||
#                                                                    ||||
#                                                                    ||||
#                                                                   \    /
#                                                                    \  /
#                                                                    \  /
#                                                                     \/
#                                                                     VV
# *****************************************************************CONTROL******************************************************************
# 
# ************************************************************ Set parameters below ********************************************************
file_path = 'DataBase.csv'
report_path = './'
#selected_labels = ['Nb', 'La', 'Ce', 'Pr', 'Nd', 'Sm', 'Eu']
# selected_labels = ['P', 'Pb', 'Ce', 'FMQ', 'Eu', 'Lu', 'Th','Nb','Dy','Hf','Y','Ta','Yb'] # 13 features
# selected_labels = [
#     'FMQ', 'P', 'Ti', 'Y', 'Nb', 'La', 'Ce', 'Pr', 'Nd', 'Sm',
#     'Eu', 'Gd', 'Tb', 'Dy', 'Ho', 'Er', 'Tm', 'Yb', 'Lu', 'Hf',
#     'Ta', 'Pb', 'Th', 'U'
# ] # 24 features
selected_labels = [
    'FMQ', 'P', 'Ti', 'Y', 'Nb', 'La', 'Ce', 'Pr', 'Nd', 'Sm',
    'Eu', 'Gd', 'Tb', 'Dy', 'Ho', 'Er', 'Tm', 'Yb', 'Lu', 'Hf',
    'Ta', 'Pb', 'Th', 'U','Ce_div_Ce_asterisk','Eu_div_Eu_asterisk','Th_div_U','U_div_Yb'
] # 28 features
# selected_labels = [
#     'FMQ', 'Ti', 'La', 'Ce', 'Pr',
#     'Eu',  'Hf',
#     'Ta', 'Pb', 'Th', 'U','Ce_div_Ce_asterisk','Eu_div_Eu_asterisk','Th_div_U','U_div_Yb'
# ] # 15 features after VIF
model_names = ['svm','rf','mlp','xgboost','knn']  # Other models can be added
maximal_number_of_combinations = 28
minimal_number_of_combinations = 28
cv_folds = 5

data_analysis_with_rf(file_path)
evaluate_and_report(file_path, report_path, model_names, selected_labels, cv_folds, maximal_number_of_combinations, minimal_number_of_combinations)
