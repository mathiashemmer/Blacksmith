#include "maingame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainGame w;
    srand(time(nullptr));

    w.show();

    return a.exec();
}
