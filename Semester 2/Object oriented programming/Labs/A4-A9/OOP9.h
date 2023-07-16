#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOP9.h"

class OOP9 : public QMainWindow
{
    Q_OBJECT

public:
    OOP9(QWidget *parent = nullptr);
    ~OOP9();

private:
    Ui::OOP9Class ui;
};
