/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_EvaluateWindow;
    QPushButton *pushButton_TrainWindow;
    QPushButton *pushButton_PredictWindow;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);


        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_EvaluateWindow = new QPushButton(widget);
        pushButton_EvaluateWindow->setObjectName("pushButton_EvaluateWindow");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_EvaluateWindow->sizePolicy().hasHeightForWidth());
        pushButton_EvaluateWindow->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_EvaluateWindow);

        pushButton_TrainWindow = new QPushButton(widget);
        pushButton_TrainWindow->setObjectName("pushButton_TrainWindow");
        sizePolicy.setHeightForWidth(pushButton_TrainWindow->sizePolicy().hasHeightForWidth());
        pushButton_TrainWindow->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_TrainWindow);

        pushButton_PredictWindow = new QPushButton(widget);
        pushButton_PredictWindow->setObjectName("pushButton_PredictWindow");
        sizePolicy.setHeightForWidth(pushButton_PredictWindow->sizePolicy().hasHeightForWidth());
        pushButton_PredictWindow->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_PredictWindow);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_EvaluateWindow->setText(QCoreApplication::translate("MainWindow", "Evaluate", nullptr));
        pushButton_TrainWindow->setText(QCoreApplication::translate("MainWindow", "Train", nullptr));
        pushButton_PredictWindow->setText(QCoreApplication::translate("MainWindow", "Predict", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
