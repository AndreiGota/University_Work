#include "OOPExam.h"

OOPExam::OOPExam(Doctor& doctor, Service& serv, QWidget *parent)
    : QWidget(parent), serv(serv), doctor(doctor)
{
    ui.setupUi(this);
    this->populateList();
    //this->connectSignalsAndSlots();
}

OOPExam::~OOPExam()
{}

void OOPExam::update()
{
    this->populateList();
}

void OOPExam::populateList()
{
    ui.patientListWidget->clear();
    /*string doctorSpecialization = doctor.getSpecialization();
    for (int i = 0; i < this->serv.getAllPatients().size(); i++) {
        if (this->serv.getAllPatients()[i].getSpecialization() == doctorSpecialization or this->serv.getAllPatients()[i].getDiagnosis() == "undiagnosed")
            ui.patientListWidget->addItem(QString::fromStdString(this->serv.getAllPatients()[i].toString()));
    }*/
}

void OOPExam::connectSignalsAndSlots()
{
}

void OOPExam::addPatientGUI()
{
}
