#include "MainWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <istream>

// declare the namespace
using namespace std;

int main(int argc, char *argv[])
{
    int temp;
    getline (cin, temp);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
