#include "MainWindow.h"
#include "pushButton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

   // load the folder for accessing
    //pushButton addressBook;
      //  addressBook.show();

    // show the main window
    MainWindow w;
    w.show();
    return a.exec();
}
