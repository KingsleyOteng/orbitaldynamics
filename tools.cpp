#include "tools.h"
#include <QtCore/QString>
#include <QFileDialog>
tools::tools()
{
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Address Book"), "",
           tr("Address Book (*.abk);;All Files (*)"));
}
