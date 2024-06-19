#include "processevalutionwindow.h"
#include "ui_processevalutionwindow.h"

ProcessEvalutionWindow::ProcessEvalutionWindow(QString trainingDataFilePath,
                                               QString reportSavePath,
                                               QList<QString> algorithmNames,
                                               QList<QString> features,
                                               int numberOfFolds,
                                               int maximalNumberOfCombinations,
                                               int minimalNumberOfCombinations,
                                               QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProcessEvalutionWindow)
{
    ui->setupUi(this);

    // 获取参数
    this->m_trainingDataFilePath = trainingDataFilePath;
    this->m_reportSavePath = reportSavePath;
    this->m_algorithmNames = algorithmNames;
    this->m_features = features;
    this->m_numberOfFolds = numberOfFolds;
    this->m_maximalNumberOfCombinations = maximalNumberOfCombinations;
    this->m_miniamlNumberOfCombinations = minimalNumberOfCombinations;

    // Set window attribute
    this->setFixedSize(500, 300);
    this->setWindowIcon(QIcon(":/res/icon/classifier.ico"));
    QString title = "Processing : ";
    title += this->m_trainingDataFilePath;
    this->setWindowTitle(title);

    // Initialize progressBar
    ui->progressBar->setRange(0, 0);
    ui->progressBar->setValue(0);

    this->StartProcess();
    this->runPythonScript(this->m_trainingDataFilePath,
                          this->m_reportSavePath,
                          this->m_algorithmNames,
                          this->m_features,
                          this->m_numberOfFolds,
                          this->m_maximalNumberOfCombinations,
                          this->m_miniamlNumberOfCombinations);
}

ProcessEvalutionWindow::~ProcessEvalutionWindow()
{
    delete ui;
}

void ProcessEvalutionWindow::StartProcess()
{
    ui->progressBar->setValue(0);
    ui->label_progressBar->setText("Processing...");
}

void ProcessEvalutionWindow::FinishProgress()
{
    ui->progressBar->setValue(100);
    ui->progressBar->setRange(0, 100);
    ui->label_progressBar->setText("Completed!");
}

void ProcessEvalutionWindow::runPythonScript(const QString &trainingDataPath,
                                             const QString &reportSavePath,
                                             const QList<QString> &algorithmNames,
                                             const QList<QString> &features,
                                             int numberOfFolds,
                                             int maximalNumberOfCombinations,
                                             int minimalNumberOfCombinations)
{
    QProcess *process = new QProcess(this);

    // Prepare arguments
    QStringList arguments;
    arguments << "-u"  // Unbuffered output
              << "./res/scripts/main.py"
              << "--training_data_path" << trainingDataPath
              << "--report_save_path" << reportSavePath
              << "--algorithm_names" << algorithmNames.join(",")
              << "--features" << features.join(",")
              << "--number_of_folds" << QString::number(numberOfFolds)
              << "--maximal_number_of_combinations" << QString::number(maximalNumberOfCombinations)
              << "--minimal_number_of_combinations" << QString::number(minimalNumberOfCombinations);

    // Connect process signals to slots
    connect(process, &QProcess::readyReadStandardOutput, [this, process]() {
        QString output = process->readAllStandardOutput();
        ui->textBrowser->append(output);
        ui->textBrowser->ensureCursorVisible();
    });

    connect(process, &QProcess::readyReadStandardError, [this, process]() {
        QString error = process->readAllStandardError();
        ui->textBrowser->append("<font color='red'>" + error + "</font>");
        ui->textBrowser->ensureCursorVisible();
    });

    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), [this](int exitCode, QProcess::ExitStatus exitStatus) {
        if (exitStatus == QProcess::NormalExit && exitCode == 0) {
            this->FinishProgress();
        } else {
            ui->label_progressBar->setText("Failed!");
        }
    });

    // Start the process
    process->start("python", arguments);

    if (!process->waitForStarted()) {
        ui->textBrowser->append("<font color='red'>Failed to start Python script.</font>");
        return;
    }
}
