#include "SongWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c;
    auto* x = new tableModel(c);
    auto* songWindow = new SongWindow(x);
    songWindow->show();
    return a.exec();
}
