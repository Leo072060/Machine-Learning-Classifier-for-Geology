/********************************************************************************
** Form generated from reading UI file 'processevalutionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSEVALUTIONWINDOW_H
#define UI_PROCESSEVALUTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessEvalutionWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QLabel *label_progressBar;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProcessEvalutionWindow)
    {
        if (ProcessEvalutionWindow->objectName().isEmpty())
            ProcessEvalutionWindow->setObjectName("ProcessEvalutionWindow");
        ProcessEvalutionWindow->resize(800, 600);
        centralwidget = new QWidget(ProcessEvalutionWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        verticalLayout->addWidget(widget_3);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName("progressBar");
        progressBar->setAutoFillBackground(true);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        horizontalLayout->addWidget(progressBar);

        label_progressBar = new QLabel(widget);
        label_progressBar->setObjectName("label_progressBar");

        horizontalLayout->addWidget(label_progressBar);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        textBrowser = new QTextBrowser(widget_2);
        textBrowser->setObjectName("textBrowser");

        verticalLayout_4->addWidget(textBrowser);


        verticalLayout->addWidget(widget_2);

        ProcessEvalutionWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProcessEvalutionWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        ProcessEvalutionWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ProcessEvalutionWindow);
        statusbar->setObjectName("statusbar");
        ProcessEvalutionWindow->setStatusBar(statusbar);

        retranslateUi(ProcessEvalutionWindow);

        QMetaObject::connectSlotsByName(ProcessEvalutionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProcessEvalutionWindow)
    {
        ProcessEvalutionWindow->setWindowTitle(QCoreApplication::translate("ProcessEvalutionWindow", "MainWindow", nullptr));
        label_progressBar->setText(QCoreApplication::translate("ProcessEvalutionWindow", "Processing...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessEvalutionWindow: public Ui_ProcessEvalutionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSEVALUTIONWINDOW_H
