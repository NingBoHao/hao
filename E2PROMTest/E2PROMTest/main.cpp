#include "e2prommainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    E2PROMMainWindow w;
    w.show();
///////////
    return a.exec();
}
