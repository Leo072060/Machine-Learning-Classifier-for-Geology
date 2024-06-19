#ifndef PROCESSEVALUTIONWINDOW_H
#define PROCESSEVALUTIONWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include <QDateTime>
#include <Python.h>
#include<QList>
#include <QProcess>
#include <QDir>

namespace Ui {
class ProcessEvalutionWindow;
}

class ProcessEvalutionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProcessEvalutionWindow(QString trainingDataFilePath,
                                    QString reportSavePath,
                                    QList<QString> algorithmNames,
                                    QList<QString> features,
                                    int numberOfFolds,
                                    int maximalNumberOfCombinations,
                                    int minimalNumberOfCombinations,
                                    QWidget *parent = nullptr);
    ~ProcessEvalutionWindow();

private:
    Ui::ProcessEvalutionWindow *ui;

    QTimer* m_progressTimer;
    const QString m_algorithmTotalFile="algorithmTotalFile";

    // 参数
    QString m_trainingDataFilePath;
    QString m_reportSavePath;
    QList<QString> m_algorithmNames;
    QList<QString> m_features;
    QString m_reportTemporaryStoragePath;
    int m_numberOfFolds;
    int m_maximalNumberOfCombinations;
    int m_miniamlNumberOfCombinations;

    void StartProcess();
    void FinishProgress();
    void runPythonScript(const QString &trainingDataPath,
                         const QString &reportSavePath,
                         const QList<QString> &algorithmNames,
                         const QList<QString> &features,
                         int numberOfFolds,
                         int maximalNumberOfCombinations,
                         int minimalNumberOfCombinations);
};

#endif // PROCESSEVALUTIONWINDOW_H
