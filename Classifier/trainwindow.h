#ifndef TRAINWINDOW_H
#define TRAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TrainWindow;
}

class TrainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrainWindow(QWidget *parent = nullptr);
    ~TrainWindow();

private:
    Ui::TrainWindow *ui;

signals:
    void Back();
};

#endif // TRAINWINDOW_H
