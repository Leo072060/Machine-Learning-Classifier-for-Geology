#include "evaluatewindow.h"
#include "ui_evaluatewindow.h"

EvaluateWindow::EvaluateWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EvaluateWindow)
{
    ui->setupUi(this);

    // Set window attribute
    this->setFixedSize(800,600);
    this->setWindowIcon(QIcon(":/res/icon/classifier.ico"));
    this->setWindowTitle("Evalute");

    // Initialize ButtonGroups
    this->InitializeButtonGroups();

    // Connect buttons
    connect(ui->pushButton_ImportTrainingData, &QPushButton::clicked, [=] {
        this->m_trainingDataFilePath = QFileDialog::getOpenFileName(this, "打开文件", "", "CSV Files (*.csv)");
        qDebug() << "Path of import training data : " << this->m_trainingDataFilePath;
        if (!this->m_trainingDataFilePath.isEmpty()) {
            QString tmp="Train data path : ";
            tmp+=this->m_trainingDataFilePath;
            ui->label_trainingDataFilePath->setText(tmp);

            // Read column names from the CSV file and add to the group box as checkboxes
            QFile csvFile(this->m_trainingDataFilePath);
            if (!csvFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qDebug() << "Cannot open CSV file for reading:" << this->m_trainingDataFilePath;
                return;
            }

            QTextStream in(&csvFile);
            QString headerLine = in.readLine();
            csvFile.close();
            QStringList featureNames = headerLine.split(",");

            // Remove the first column name (assuming it's the label column)
            if (!featureNames.isEmpty()) {
                featureNames.removeFirst();
            }

            // Generate feature checkboxes in a new container widget
            QWidget *containerWidget = new QWidget();
            QVBoxLayout *layout = new QVBoxLayout(containerWidget);
            for (const QString &featureName : featureNames) {
                QCheckBox *checkBox = new QCheckBox(featureName);
                this->m_checkButtonGroup_features.push_back(checkBox);
                // 默认全部选中
                checkBox->setChecked(true);

                layout->addWidget(checkBox);
            }
            containerWidget->setLayout(layout);

            // Create a scroll area and set the container widget as its widget
            QScrollArea *scrollArea = new QScrollArea(ui->groupBox_Features);
            scrollArea->setWidget(containerWidget);
            scrollArea->setWidgetResizable(true);
            scrollArea->setFixedHeight(170); // 设置滚动区域的固定高度

            // Clear the previous layout if exists and set a new layout
            if (ui->groupBox_Features->layout() != nullptr) {
                QLayoutItem *item;
                while ((item = ui->groupBox_Features->layout()->takeAt(0)) != nullptr) {
                    delete item->widget(); // 删除子部件
                    delete item; // 删除布局项
                }
                delete ui->groupBox_Features->layout();
            }
            QVBoxLayout *scrollLayout = new QVBoxLayout(ui->groupBox_Features);
            scrollLayout->addWidget(scrollArea);
        }
    });

    connect(ui->pushButton_ReportSavePath, &QPushButton::clicked, [=] {
        this->m_reportSavePath = QFileDialog::getExistingDirectory(this, "选择保存位置", "");
        qDebug() << "Report save path : " << this->m_reportSavePath;
        if (!this->m_reportSavePath.isEmpty()) {
            QString tmp = "Report save path : ";
            tmp+=this->m_reportSavePath;
            ui->label_reportSavePath->setText(tmp);
        }
    });

    connect(ui->pushButton_StartTraining,&QPushButton::clicked,[=]{
        if(0==this->m_trainingDataFilePath.size())
        {
            QMessageBox::critical(this,"Error","Please import training data!");
            return;
        }
        if(0==this->m_reportSavePath.size())
        {
            QMessageBox::critical(this,"Error","Please select report save path!");
            return;
        }

        QList<QString> selected_algorithms;
        for (auto &e : this->m_checkButtonGroup_algorithmNames)
        {
            if (e->isChecked())
            {
                selected_algorithms.push_back(e->text());
            }
        }
        QList<QString> selected_features;
        for(auto &e:this->m_checkButtonGroup_features)
        {
            if(e->isChecked())
            {
                selected_features.push_back(e->text());
            }
        }

        if(0==selected_algorithms.size())
        {
            QMessageBox::critical(this,"Error","Please select at least one algorithm!");
            return;
        }
        if(0==selected_features.size())
        {
            QMessageBox::critical(this,"Error","Please select at least one feature!");
            return;
        }
        if(0==ui->spinBox_NumberOfFolds->value())
        {
            QMessageBox::critical(this,"Error","Number of Folds for Cross-Validation can not be zero!");
            return;
        }
        if(0==ui->spinBox_MinimunNumberOfCombinations->value())
        {
            QMessageBox::critical(this,"Error","Minimun number of combinations can not be zero!");
            return;
        }
        if(0==ui->spinBox_MaximunNumberOfCombinations->value())
        {
            QMessageBox::critical(this,"Error","Maximun number of combinations can not be zero!");
            return;
        }
        if(ui->spinBox_MinimunNumberOfCombinations->value() > selected_features.size())
        {
            QMessageBox::critical(this,"Error","Minimun number of combinations must smaller than number of features can not be zero!");
            return;
        }
        if(ui->spinBox_MinimunNumberOfCombinations->value()>ui->spinBox_MaximunNumberOfCombinations->value())
        {
            QMessageBox::critical(this,"Error","Minimun number of combinations must smaller than Maximun number of combinations can not be zero!");
            return;
        }

        ProcessEvalutionWindow* tmp_ProcessEvalutionWindow=new ProcessEvalutionWindow(this->m_trainingDataFilePath,
                                                                                        this->m_reportSavePath,
                                                                                        selected_algorithms,
                                                                                        selected_features,
                                                                                        ui->spinBox_NumberOfFolds->value(),
                                                                                        ui->spinBox_MaximunNumberOfCombinations->value(),
                                                                                        ui->spinBox_MinimunNumberOfCombinations->value(),
                                                                                        this);
        tmp_ProcessEvalutionWindow->show();
    });
    connect(ui->pushButton_Back,&QPushButton::clicked,[=]{
        emit this->Back();
    });
}

EvaluateWindow::~EvaluateWindow()
{
    delete ui;
}

void EvaluateWindow::LoadAlgorithmNames() {
    QFile file(this->m_algorithmNamesPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can not open file for reading:" << this->m_algorithmNamesPath;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty()) {
            this->m_algorithmNames.append(line);
        }
    }
    file.close();
}

void EvaluateWindow::InitializeButtonGroups() {
    this->LoadAlgorithmNames();

    QVBoxLayout *layout = nullptr;
    int id = 0;

    layout = new QVBoxLayout();
    id = 0;
    for (const QString &algorithmName : this->m_algorithmNames) {
        QCheckBox *checkBox = new QCheckBox(algorithmName);
        this->m_checkButtonGroup_algorithmNames.push_back(checkBox);
        layout->addWidget(checkBox);

        if (id < 2) {
            checkBox->setChecked(true);
        }
        id++;
    }
    ui->groupBox_Algorithm->setLayout(layout);
}
