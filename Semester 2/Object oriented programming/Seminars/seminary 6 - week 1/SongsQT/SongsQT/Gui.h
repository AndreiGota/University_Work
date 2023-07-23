#pragma once
#include <QWidget>
#include "Service.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>

class Gui :public QWidget {
private:
	Service &service;
	QListWidget* songsListWidget;
	QLineEdit* artistLineEdit, * titleLineEdit, *sourceLineEdit;
	QPushButton* addButton, * deleteButton;
	void initGui();
	void populateSongsList();
	void connectSignalsAndSlots();
	int getSelectedIndexFromSongsList();
	void addSong();
	void deleteSong();
public:
	Gui(Service& serv);
};
