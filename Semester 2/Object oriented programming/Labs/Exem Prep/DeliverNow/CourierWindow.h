#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CourierWindow.h"
#include "Controller.h"

class CourierWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    CourierWindow(Controller& c, Courier cou, QWidget *parent = nullptr);
    ~CourierWindow();
    void populateUndeliveredPackagesList();
    void showSpecificStreets();
    void update() override;
    void deliverPackage();
private:
    Ui::CourierWindowClass ui;
    Controller& controller;
    Courier courier;
};
