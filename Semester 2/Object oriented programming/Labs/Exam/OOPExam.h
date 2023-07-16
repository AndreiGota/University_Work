#pragma once

#include <QtWidgets/QWidget>
#include "ui_OOPExam.h"
#include "Observer.h"
#include "Service.h"

class OOPExam : public QWidget, public Observer
{
    Q_OBJECT

public:
    OOPExam(Doctor& doctor, Service& serv, QWidget *parent = nullptr);
    ~OOPExam();
    void update() override;
private:
    Ui::OOPExamClass ui;
    Service& serv;
    Doctor& doctor;
    void populateList();
    void connectSignalsAndSlots();
    void addPatientGUI();
};
