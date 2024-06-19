#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set window attribute
    this->setFixedSize(800,600);
    this->setWindowIcon(QIcon(":/res/icon/classifier.ico"));
    this->setWindowTitle("Classifier");
    ui->label->setPixmap(QPixmap(":/res/pic/mainWindow.png"));
    ui->label->setScaledContents(true);
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->adjustSize();

    // Initialize members
    this->m_TrainWindow=new TrainWindow;
    this->m_PredictWindow=new PredictWindow;
    this->m_EvaluateWindow=new EvaluateWindow;

    // Set working directory
    QString appDir = QCoreApplication::applicationDirPath();
    qDebug() << "Application directory:" << appDir;
    QDir::setCurrent(appDir);
    qDebug() << "Current working directory:" << QDir::currentPath();

    // Connect buttons
    // connect(ui->pushButton_TrainWindow,&QPushButton::clicked,[=]{
    //     this->m_TrainWindow->setGeometry(this->geometry());
    //     this->m_TrainWindow->show();
    //     this->hide();
    // });
    // connect(ui->pushButton_PredictWindow,&QPushButton::clicked,[=]{
    //     this->m_PredictWindow->setGeometry(this->geometry());
    //     this->m_PredictWindow->show();
    //     this->hide();
    // });
    connect(ui->pushButton_EvaluateWindow,&QPushButton::clicked,[=]{
        this->m_EvaluateWindow->setGeometry(this->geometry());
        this->m_EvaluateWindow->show();
        this->hide();
    });

    // Listen to other windows
    connect(this->m_TrainWindow,&TrainWindow::Back,[=]{
        this->setGeometry(this->m_TrainWindow->geometry());
        this->show();
        this->m_TrainWindow->hide();
    });
    connect(this->m_PredictWindow,&PredictWindow::Back,[=]{
        this->setGeometry(this->m_PredictWindow->geometry());
        this->show();
        this->m_PredictWindow->hide();
    });
    connect(this->m_EvaluateWindow,&EvaluateWindow::Back,[=]{
        this->setGeometry(this->m_EvaluateWindow->geometry());
        this->show();
        this->m_EvaluateWindow->hide();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
