#include "OOPExam.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service serv;
    vector<Doctor> allDoctors = serv.getAllDoctors();
    //vector<OOPExam*> doctorWindows;
    //OOPExam w{ serv.getAllDoctors()[1], serv };
    // w.show();
    /*for (int i = 0; i < allDoctors.size(); i++) {
        OOPExam* doctorWindow = new OOPExam(allDoctors[i], serv);
        doctorWindow->setWindowTitle(QString::fromStdString(allDoctors[i].getName()));
        serv.addObserver(doctorWindow);
        doctorWindows.push_back(doctorWindow);
    }
    
    for (int i = 0; i < doctorWindows.size(); i++) {
        doctorWindows[i]->show();
    }*/
    return a.exec();
}
