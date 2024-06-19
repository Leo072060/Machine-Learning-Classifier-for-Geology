#include "processtrainwindow.h"
#include "ui_processwindow.h"

ProcessWindow::ProcessWindow(QString trainingDataFilePath,QString algorithmName,QList<QString> algorithmEvaluationMethodName,int numberOfFolds,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProcessWindow)
{
    ui->setupUi(this);

     Py_Initialize();

    this->m_trainingDataFilePath=trainingDataFilePath;
    this->m_algorithmName=algorithmName;
    this->m_algorithmEvaluationMethodName=algorithmEvaluationMethodName;
    this->m_numberOfFolds=numberOfFolds;
    this->m_modelTemporaryStoragePath=this->CreateTimestampedFilePath("./res/temporaryStorage/model",".joblib");
    this->m_reportTemporaryStoragePath=this->CreateTimestampedFilePath("./res/temporaryStorage/report","");
    qDebug()<<"Processing : "<<this->m_trainingDataFilePath<<" "<<this->m_algorithmName<<" "
             <<this->m_algorithmEvaluationMethodName<<" "<<this->m_modelTemporaryStoragePath<<" "
             <<this->m_reportTemporaryStoragePath<<" "<<this->m_numberOfFolds;

    // Set window attribute
    this->setFixedSize(500,300);
    //this->setWindowIcon(QIcon(":/resource/image/Coin0001.png"));
    QString title="Processing : ";
    title+=this->m_trainingDataFilePath;
    this->setWindowTitle(title);

    // Initialize timer
    this->m_progressTimer = new QTimer(this);

    // Initialize progressBar
    ui->progressBar->setRange(0, 0);
    ui->progressBar->setValue(0);

    this->StartProcess();

    int funcBack=this->TrainAndSaveModel();
    if(0==funcBack)
    {
        qDebug()<<"Call TrainAndSaveModel successfully.";
    }
    else
    {
        qDebug()<<"Call TrainAndSaveModel failed.";
    }

    for(QString algorithmEvaluationMethodName:this->m_algorithmEvaluationMethodName)
    {
        qDebug()<<"Evaluating : "<<algorithmEvaluationMethodName;
        int funcBack=this->EvaluateAlgorithmAndGenerateReport(algorithmEvaluationMethodName);
        if(0==funcBack)
        {
            qDebug()<<"Call "<<algorithmEvaluationMethodName<<" successfully.";
        }
        else
        {
            qDebug()<<"Call "<<algorithmEvaluationMethodName<<" failed.";
        }
    }


}

ProcessWindow::~ProcessWindow(){
        Py_Finalize();
    delete ui;
}

void ProcessWindow::StartProcess(){
    ui->progressBar->setValue(0);
    this->m_progressTimer->start(50);
    ui->label_progressBar->setText("Processing...");
}

void ProcessWindow::FinishProgress(){
    this->m_progressTimer->stop();
    ui->progressBar->setValue(1);
    ui->progressBar->setRange(0, 1);
    ui->label_progressBar->setText("Completed!");
    // 可以添加更多的视觉反馈，如弹出消息框
    //QMessageBox::information(this, "Process Complete", "The process has completed successfully!");
}

QString ProcessWindow::CreateTimestampedFilePath(QString fileName,QString suffix) {
    QDateTime now = QDateTime::currentDateTime();
    QString timestamp = now.toString("_yyyyMMdd_hhmmsszzz");
    QString ret = fileName+timestamp+suffix;
    return ret;
}

int ProcessWindow::TrainAndSaveModel() {

    if (!Py_IsInitialized()) {
        qDebug() << "Initialize Python failed.";
        return -1;
    }

    // 导入 sys 模块并设置 Python 脚本路径
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./res/algorithm')"); // 确保脚本目录正确

    // 创建算法模块指针
    PyObject* pModuleAlgorithm = PyImport_ImportModule(this->m_algorithmTotalFile.toStdString().c_str());
    if (!pModuleAlgorithm) {
        PyErr_Print();
        qDebug() << "Failed to import module : "<<this->m_algorithmTotalFile;
        Py_Finalize();
        return -1;
    }
    else {
        qDebug() << "Successful to import module : "<<this->m_algorithmTotalFile;
    }

    // 获取函数指针
    PyObject* pFunc = PyObject_GetAttrString(pModuleAlgorithm, "train_and_save_model");
    if (!pFunc || !PyCallable_Check(pFunc)) {
        PyErr_Print();
        qDebug() << "Failed to get "<<"train_and_save_model"<<" function or function is not callable.";
        Py_DECREF(pModuleAlgorithm);
        Py_Finalize();
        return -1;
    }
    else {
        qDebug() << "Successful to get "<<"train_and_save_model"<<" function.";
    }

    // 调用 Python 函数
    PyObject* pPara = PyTuple_New(3);  // 创建一个大小为3的元组
    if (!pPara) {
        // 处理 PyTuple_New 失败的情况
        qDebug() << "Failed to create Python tuple";
        return -1;
    }

    // 将第一个参数（m_trainingDataFilePath）加入元组
    PyObject* pValue1 = Py_BuildValue("s", this->m_trainingDataFilePath.toStdString().c_str());
    if (!pValue1) {
        // 处理 Py_BuildValue 失败的情况
        qDebug() << "Failed to create Python string from m_trainingDataFilePath";
        Py_DECREF(pPara);
        return -1;
    }
    PyTuple_SetItem(pPara, 0, pValue1);

    // 将第二个参数（m_modelTemporaryStoragePath）加入元组
    PyObject* pValue2 = Py_BuildValue("s", this->m_modelTemporaryStoragePath.toStdString().c_str());
    if (!pValue2) {
        // 处理 Py_BuildValue 失败的情况
        qDebug() << "Failed to create Python string from m_temporaryStoragePath";
        Py_DECREF(pPara);
        return -1;
    }
    PyTuple_SetItem(pPara, 1, pValue2);

    // 将第三个参数（algorithmName）加入元组
    PyObject* pValue3 = Py_BuildValue("s", this->m_algorithmName.toStdString().c_str());
    if (!pValue3) {
        // 处理 Py_BuildValue 失败的情况
        qDebug() << "Failed to create Python string from algorithmName";
        Py_DECREF(pPara);
        return -1;
    }
    PyTuple_SetItem(pPara, 2, pValue3);

    PyObject *FuncBack = PyObject_CallObject(pFunc, pPara);

    if (FuncBack != nullptr) {
        int ret = 0;
        if (PyArg_Parse(FuncBack, "i", &ret)) {
            qDebug() << "Function returned:" << ret;
        }
        else {
            PyErr_Print();
            qDebug() << "Failed to parse return value";
            return -1;
        }
        Py_DECREF(FuncBack);
    }
    else {
        PyErr_Print();
        qDebug() << "Function call failed";
        return -1;
    }

    // 清理
    Py_DECREF(pFunc);
    Py_DECREF(pModuleAlgorithm);


    return 0;
}

int ProcessWindow::EvaluateAlgorithmAndGenerateReport(QString algorithmEvaluationMethodName) {
    // 初始化 Python 解释器

    if (!Py_IsInitialized()) {
        qDebug() << "Initialize Python failed.";
        return -1;
    }

    // 导入 sys 模块并设置 Python 脚本路径
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./res/algorithm')"); // 确保脚本目录正确

    // 创建算法模块指针
    PyObject* pModuleAlgorithm = PyImport_ImportModule(this->m_algorithmEvaluationMethodTotalFile.toStdString().c_str());
    if (!pModuleAlgorithm) {
        PyErr_Print();
        qDebug() << "Failed to import module : "<<this->m_algorithmEvaluationMethodTotalFile;
        Py_Finalize();
        return -1;
    }
    else {
        qDebug() << "Successful to import module : "<<this->m_algorithmEvaluationMethodTotalFile;
    }

    // 获取评估算法函数指针
    PyObject* pFunc = PyObject_GetAttrString(pModuleAlgorithm, "evaluate_algorithm_and_generate_report");
    if (!pFunc || !PyCallable_Check(pFunc)) {
        PyErr_Print();
        qDebug() << "Failed to get "<< "evaluate_algorithm_and_generate_report" <<" function or function is not callable.";
        Py_DECREF(pModuleAlgorithm);
        Py_Finalize();
        return -1;
    }
    else {
        qDebug() << "Successful to get "<< "evaluate_algorithm_and_generate_report" <<" function.";
    }

    // 调用 Python 函数
    PyObject* pPara = PyTuple_New(5);  // 创建一个大小为5的元组
    if (!pPara) {
        // 处理 PyTuple_New 失败的情况
        qDebug() << "Failed to create Python tuple";
        return -1;
    }

    // 将参数加入元组
    PyObject* pValue1 = Py_BuildValue("s", this->m_trainingDataFilePath.toStdString().c_str());
    PyTuple_SetItem(pPara, 0, pValue1);

    PyObject* pValue2 = Py_BuildValue("s", this->m_algorithmName.toStdString().c_str());
    PyTuple_SetItem(pPara, 1, pValue2);

    PyObject* pValue3 = Py_BuildValue("s", this->m_reportTemporaryStoragePath.toStdString().c_str());
    PyTuple_SetItem(pPara, 2, pValue3);

    PyObject* pValue4 = Py_BuildValue("i", this->m_numberOfFolds);
    PyTuple_SetItem(pPara, 3, pValue4);

    PyObject* pValue5 = Py_BuildValue("s", algorithmEvaluationMethodName.toStdString().c_str());
    PyTuple_SetItem(pPara, 4, pValue5);

    // 调用 Python 函数并处理返回值
    PyObject *FuncBack = PyObject_CallObject(pFunc, pPara);
    if (FuncBack != nullptr) {
        int ret = 0;
        if (PyArg_Parse(FuncBack, "i", &ret)) {
            qDebug() << "Function returned:" << ret;
        }
        else {
            PyErr_Print();
            qDebug() << "Failed to parse return value";
            return -1;
        }
        Py_DECREF(FuncBack);
    }
    else {
        PyErr_Print();
        qDebug() << "Function call failed";
        return -1;
    }

    // 清理
    Py_DECREF(pFunc);
    Py_DECREF(pModuleAlgorithm);


    return 0;
}
