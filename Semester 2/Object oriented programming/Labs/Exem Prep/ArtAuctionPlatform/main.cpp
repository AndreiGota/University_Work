#include "UserWindow.h"
#include <QtWidgets/QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller controller;
    vector<UserWindow*> windows;
    for (auto& it : controller.getAllUsers()) {
        UserWindow* window = new UserWindow(controller, it);
        windows.push_back(window);
    }
    for (auto& window : windows) {
        controller.addObserver(window);
        window->show();
    }
    controller.writeItemsToFile();
    return a.exec();
}
