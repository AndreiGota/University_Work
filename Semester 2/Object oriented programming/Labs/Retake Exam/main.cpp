#include "PersonWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c{};
    vector<PersonWindow*> windows;
    for (auto& it : c.getPersons()) {
        PersonWindow* window = new PersonWindow(c, it);
        windows.push_back(window);
    }

    for (auto& it : windows) {
        c.addObserver(it);
        it->show();
    }
    return a.exec();
}
