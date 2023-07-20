#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SongsQT.h"

class SongsQT : public QMainWindow
{
    Q_OBJECT

public:
    SongsQT(QWidget *parent = Q_NULLPTR);

private:
    Ui::SongsQTClass ui;
};
