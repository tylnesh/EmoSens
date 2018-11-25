#include "mainwindow.h"
#include <QApplication>
#include "keypresseventfilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    KeyPressEventFilter *filter = new KeyPressEventFilter(&a);
       a.installEventFilter(filter);

    MainWindow w;
    w.show();

    return a.exec();
}
