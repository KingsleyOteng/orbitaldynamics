#include "MainWindow.h"
#include "pushButton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    pushButton addressBook;
        addressBook.show();

    MainWindow w;
    w.show();
    return a.exec();
}
