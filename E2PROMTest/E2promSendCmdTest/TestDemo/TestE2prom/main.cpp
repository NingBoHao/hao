#include "teste2promwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestE2promWidget w;
    w.show();

    return a.exec();
}
