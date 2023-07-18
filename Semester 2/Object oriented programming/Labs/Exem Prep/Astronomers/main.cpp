#include "AstronomerWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c{};
    auto* myModel = new starModel{ c };
    for (auto& it : c.getAstronomers()) {
        auto* newWindow = new AstronomerWindow{ myModel, it };
        newWindow->setWindowTitle(QString::fromStdString(it.getAstronomerName()));
        newWindow->show();
    }
    return a.exec();
}
