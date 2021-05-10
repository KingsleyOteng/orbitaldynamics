#include "MainWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <istream>

// declare the namespace
using namespace std;

int main(int argc, char *argv[])
{
    QString yourText;
    QFile file;
    file.open(stdin, QIODevice::ReadOnly);
    QTextStream qtin(&file);
    qtin >> yourText;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
