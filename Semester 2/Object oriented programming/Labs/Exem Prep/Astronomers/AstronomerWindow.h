#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AstronomerWindow.h"
#include "starsModel.h"

class AstronomerWindow : public QMainWindow
{
    Q_OBJECT

public:
    AstronomerWindow(starModel* m, Astronomer a, QWidget *parent = nullptr);
    ~AstronomerWindow();
    void addStarGUI();
private:
    Ui::AstronomerWindowClass ui;
    starModel* model;
    Astronomer astronomer;
};
