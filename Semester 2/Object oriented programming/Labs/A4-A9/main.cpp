#include "OOP9.h"
#include <QtWidgets/QApplication>
#include <crtdbg.h>
#include "ADMINservice.h"
#include <QApplication>
#include "validators.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<DogObject> adminRepoVector;
    adminRepoVector.reserve(10);
    string filename = R"(C:\Users\Andrei\source\repos\OOP9\OOP9\dogs.txt)";
    AdministratorRepository repo{ adminRepoVector, filename };
    repo.initialiseAdminRepo();
    AdministratorService service{ repo };
    UserService userService{ repo };
    DogObjectValidator validator{};
    GUI gui{ service, userService, validator};
    gui.show();
    return a.exec();
}
