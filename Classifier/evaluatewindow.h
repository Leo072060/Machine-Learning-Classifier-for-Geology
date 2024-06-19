#ifndef EVALUATEWINDOW_H
#define EVALUATEWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QButtonGroup>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include<QDir>
#include<QRadioButton>
#include<QMessageBox>
#include<QCheckBox>
#include<QList>
#include <QScrollArea>
#include"processevalutionwindow.h"

namespace Ui {
class EvaluateWindow;
}

class EvaluateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EvaluateWindow(QWidget *parent = nullptr);
    ~EvaluateWindow();

private:
    Ui::EvaluateWindow *ui;

    QString m_trainingDataFilePath;
    QString m_reportSavePath;
    // Algorithm
    const QString m_algorithmNamesPath=":/res/system/algorithmNames.txt";
    QStringList m_algorithmNames;
    QList<QCheckBox*> m_checkButtonGroup_algorithmNames;
    // Features
    QList<QCheckBox*> m_checkButtonGroup_features;
    QStringList m_features;

    void LoadAlgorithmNames();
    void InitializeButtonGroups();

signals:
    void Back();
};

#endif // EVALUATEWINDOW_H
