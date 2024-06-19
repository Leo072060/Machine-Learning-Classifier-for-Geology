#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 初始化Python解释器
    Py_Initialize();

    MainWindow w;
    w.show();
    return a.exec();

    // 终止Python解释器
    Py_Finalize();
}
