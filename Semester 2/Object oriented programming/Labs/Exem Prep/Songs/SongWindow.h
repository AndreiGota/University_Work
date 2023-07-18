#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SongWindow.h"
#include "tableModel.h"

class SongWindow : public QMainWindow
{
    Q_OBJECT

public:
    SongWindow(tableModel* songModel,QWidget *parent = nullptr);
    ~SongWindow();
    void onSongSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
    void updateSongGUI();
private:
    Ui::SongWindowClass ui;
    tableModel* songModel;
};
