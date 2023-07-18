#include "CourierWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c{};
    /*vector<DepartamentWindow*> windows;
    for (auto& it : controller.getDepartaments()) {
        DepartamentWindow* window = new DepartamentWindow(controller, it);
        windows.push_back(window);
    }
    
    for (auto& window : windows) {
        controller.addObserver(window);
        window->show();
    }*/
    vector<CourierWindow*> windows;
    for (auto& it : c.getCouriers()) {
        CourierWindow* window = new CourierWindow{ c, it };
        windows.push_back(window);
    }
    for (auto& window : windows) {
        c.addObserver(window);
        window->show();
    }
    return a.exec();
}
