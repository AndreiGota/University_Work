#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PersonWindow.h"
#include "Controller.h"

class PersonWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    PersonWindow(Controller& c, Person p,QWidget *parent = nullptr);
    ~PersonWindow();
    void populateEventList();
    void addEventGUI();
    void update() override;
    void showSpecificEvents();
private:
    Ui::PersonWindowClass ui;
    Controller& controller;
    Person person;
};
