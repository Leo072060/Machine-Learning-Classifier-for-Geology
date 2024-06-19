#ifndef PROCESSTRAINWINDOW_H
#define PROCESSTRAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include <QDateTime>
#include <Python.h>
#include<QList>

namespace Ui {
class ProcessWindow;
}

class ProcessWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProcessWindow(QString trainingDataFilePath,QString algorithmName,QList<QString> algorithmEvaluationMethodName,int numberOfFolds,QWidget *parent = nullptr);
    ~ProcessWindow();

private:
    Ui::ProcessWindow *ui;

    QTimer* m_progressTimer;
    QString m_trainingDataFilePath;
    const QString m_algorithmTotalFile="algorithmTotalFile";
    const QString m_algorithmEvaluationMethodTotalFile="algorithmEvaluationMethodTotalFile";
    QString m_algorithmName;
    QList<QString> m_algorithmEvaluationMethodName;
    QString m_modelTemporaryStoragePath;
    QString m_reportTemporaryStoragePath;
    int m_numberOfFolds;


    void StartProcess();
    void FinishProgress();
    int TrainAndSaveModel();
    int EvaluateAlgorithmAndGenerateReport(QString algorithmEvaluationMethodName);
    QString CreateTimestampedFilePath(QString fileName,QString suffix);

};

#endif // PROCESSTRAINWINDOW_H
