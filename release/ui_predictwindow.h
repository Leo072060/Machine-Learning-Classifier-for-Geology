/********************************************************************************
** Form generated from reading UI file 'predictwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREDICTWINDOW_H
#define UI_PREDICTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PredictWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PredictWindow)
    {
        if (PredictWindow->objectName().isEmpty())
            PredictWindow->setObjectName("PredictWindow");
        PredictWindow->resize(800, 600);
        centralwidget = new QWidget(PredictWindow);
        centralwidget->setObjectName("centralwidget");
        PredictWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PredictWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        PredictWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PredictWindow);
        statusbar->setObjectName("statusbar");
        PredictWindow->setStatusBar(statusbar);

        retranslateUi(PredictWindow);

        QMetaObject::connectSlotsByName(PredictWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PredictWindow)
    {
        PredictWindow->setWindowTitle(QCoreApplication::translate("PredictWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PredictWindow: public Ui_PredictWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICTWINDOW_H
