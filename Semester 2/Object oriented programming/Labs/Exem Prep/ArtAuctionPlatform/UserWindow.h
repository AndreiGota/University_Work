#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UserWindow.h"
#include "Controller.h"
#include <qobject.h>

class UserWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    UserWindow(Controller& controller, User u, QWidget *parent = nullptr);
    ~UserWindow();
    void update() override;

    void populateList();
    void displaySpecificItems();
    void addItemGUI();
    void onSongSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);

private:
    Ui::UserWindowClass ui;
    Controller& controller;
    User user;
};
