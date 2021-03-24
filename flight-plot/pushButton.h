#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#endif // PUSHBUTTON_H

#include <QWidget>
#include <QMap>
#include "finddialog.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class pushButton : public QWidget
{
    Q_OBJECT

    public:
        pushButton(QWidget *parent = nullptr);
        enum Mode { NavigationMode, AddingMode, EditingMode };

    public slots:
        void addContact();
        void editContact();
        void submitContact();
        void cancel();
        void removeContact();
        void findContact();
        void next();
        void previous();
    //! [save and load functions declaration]
        void saveToFile();
        void loadFromFile();
    //! [save and load functions declaration]

    private:
        void updateInterface(Mode mode);

        QPushButton *addButton;
        QPushButton *editButton;
        QPushButton *removeButton;
        QPushButton *findButton;
        QPushButton *submitButton;
        QPushButton *cancelButton;
        QPushButton *nextButton;
        QPushButton *previousButton;
    //! [save and load buttons declaration]
        QPushButton *loadButton;
        QPushButton *saveButton;
    //! [save and load buttons declaration]
        QLineEdit *nameLine;
        QTextEdit *addressText;

        QMap<QString, QString> contacts;
        finddialog *dialog;
        QString oldName;
        QString oldAddress;
        Mode currentMode;
};
