#ifndef PREDICTWINDOW_H
#define PREDICTWINDOW_H

#include <QMainWindow>

namespace Ui {
class PredictWindow;
}

class PredictWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PredictWindow(QWidget *parent = nullptr);
    ~PredictWindow();

private:
    Ui::PredictWindow *ui;

signals:
    void Back();
};

#endif // PREDICTWINDOW_H
