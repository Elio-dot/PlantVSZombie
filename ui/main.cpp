#include <QApplication>
#include <stdio.h>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    printf("hello,world\n");
    w.setFixedSize(900, 600);
    w.setWindowTitle("植物大战僵尸");
    w.show();
    return a.exec();
}
