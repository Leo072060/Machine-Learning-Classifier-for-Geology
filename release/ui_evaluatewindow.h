/********************************************************************************
** Form generated from reading UI file 'evaluatewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVALUATEWINDOW_H
#define UI_EVALUATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EvaluateWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_trainingDataFilePath;
    QLabel *label_reportSavePath;
    QGroupBox *groupBox_Algorithm;
    QGroupBox *groupBox_Features;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spinBox_NumberOfFolds;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *spinBox_MaximunNumberOfCombinations;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *spinBox_MinimunNumberOfCombinations;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_ImportTrainingData;
    QPushButton *pushButton_ReportSavePath;
    QPushButton *pushButton_StartTraining;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Help;
    QPushButton *pushButton_Back;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EvaluateWindow)
    {
        if (EvaluateWindow->objectName().isEmpty())
            EvaluateWindow->setObjectName("EvaluateWindow");
        EvaluateWindow->resize(800, 600);
        centralwidget = new QWidget(EvaluateWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_trainingDataFilePath = new QLabel(widget);
        label_trainingDataFilePath->setObjectName("label_trainingDataFilePath");

        verticalLayout_2->addWidget(label_trainingDataFilePath);

        label_reportSavePath = new QLabel(widget);
        label_reportSavePath->setObjectName("label_reportSavePath");

        verticalLayout_2->addWidget(label_reportSavePath);

        groupBox_Algorithm = new QGroupBox(widget);
        groupBox_Algorithm->setObjectName("groupBox_Algorithm");

        verticalLayout_2->addWidget(groupBox_Algorithm);

        groupBox_Features = new QGroupBox(widget);
        groupBox_Features->setObjectName("groupBox_Features");

        verticalLayout_2->addWidget(groupBox_Features);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(widget_4);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        spinBox_NumberOfFolds = new QSpinBox(widget_4);
        spinBox_NumberOfFolds->setObjectName("spinBox_NumberOfFolds");

        horizontalLayout_3->addWidget(spinBox_NumberOfFolds);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(widget_5);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        spinBox_MaximunNumberOfCombinations = new QSpinBox(widget_5);
        spinBox_MaximunNumberOfCombinations->setObjectName("spinBox_MaximunNumberOfCombinations");

        horizontalLayout_4->addWidget(spinBox_MaximunNumberOfCombinations);


        verticalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName("widget_6");
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(widget_6);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        spinBox_MinimunNumberOfCombinations = new QSpinBox(widget_6);
        spinBox_MinimunNumberOfCombinations->setObjectName("spinBox_MinimunNumberOfCombinations");

        horizontalLayout_5->addWidget(spinBox_MinimunNumberOfCombinations);


        verticalLayout_2->addWidget(widget_6);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName("widget_7");
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButton_ImportTrainingData = new QPushButton(widget_7);
        pushButton_ImportTrainingData->setObjectName("pushButton_ImportTrainingData");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_ImportTrainingData->sizePolicy().hasHeightForWidth());
        pushButton_ImportTrainingData->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(pushButton_ImportTrainingData);

        pushButton_ReportSavePath = new QPushButton(widget_7);
        pushButton_ReportSavePath->setObjectName("pushButton_ReportSavePath");
        sizePolicy1.setHeightForWidth(pushButton_ReportSavePath->sizePolicy().hasHeightForWidth());
        pushButton_ReportSavePath->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(pushButton_ReportSavePath);


        verticalLayout->addWidget(widget_7);

        pushButton_StartTraining = new QPushButton(widget_2);
        pushButton_StartTraining->setObjectName("pushButton_StartTraining");
        sizePolicy1.setHeightForWidth(pushButton_StartTraining->sizePolicy().hasHeightForWidth());
        pushButton_StartTraining->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton_StartTraining);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_Help = new QPushButton(widget_3);
        pushButton_Help->setObjectName("pushButton_Help");
        sizePolicy1.setHeightForWidth(pushButton_Help->sizePolicy().hasHeightForWidth());
        pushButton_Help->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_Help);

        pushButton_Back = new QPushButton(widget_3);
        pushButton_Back->setObjectName("pushButton_Back");
        sizePolicy1.setHeightForWidth(pushButton_Back->sizePolicy().hasHeightForWidth());
        pushButton_Back->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_Back);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(widget_2);

        EvaluateWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EvaluateWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        EvaluateWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EvaluateWindow);
        statusbar->setObjectName("statusbar");
        EvaluateWindow->setStatusBar(statusbar);

        retranslateUi(EvaluateWindow);

        QMetaObject::connectSlotsByName(EvaluateWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EvaluateWindow)
    {
        EvaluateWindow->setWindowTitle(QCoreApplication::translate("EvaluateWindow", "MainWindow", nullptr));
        label_trainingDataFilePath->setText(QCoreApplication::translate("EvaluateWindow", "Please import training data.", nullptr));
        label_reportSavePath->setText(QCoreApplication::translate("EvaluateWindow", "Please select the location you want to save.", nullptr));
        groupBox_Algorithm->setTitle(QCoreApplication::translate("EvaluateWindow", "Algorithm", nullptr));
        groupBox_Features->setTitle(QCoreApplication::translate("EvaluateWindow", "Features", nullptr));
        label->setText(QCoreApplication::translate("EvaluateWindow", "Number of Folds for Cross-Validation : ", nullptr));
        label_2->setText(QCoreApplication::translate("EvaluateWindow", "Maximum number of combinations : ", nullptr));
        label_3->setText(QCoreApplication::translate("EvaluateWindow", "Minimum number of combinations : ", nullptr));
        pushButton_ImportTrainingData->setText(QCoreApplication::translate("EvaluateWindow", "Import training data", nullptr));
        pushButton_ReportSavePath->setText(QCoreApplication::translate("EvaluateWindow", "Report save path", nullptr));
        pushButton_StartTraining->setText(QCoreApplication::translate("EvaluateWindow", "Start training", nullptr));
        pushButton_Help->setText(QCoreApplication::translate("EvaluateWindow", "Help", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("EvaluateWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EvaluateWindow: public Ui_EvaluateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVALUATEWINDOW_H
