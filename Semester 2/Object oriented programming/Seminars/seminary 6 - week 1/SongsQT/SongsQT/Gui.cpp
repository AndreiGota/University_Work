#include "Gui.h"
#include <qlayout.h>
#include <QFormLayout>
#include <string>
#include "RepositoryExceptions.h"
#include <QMessageBox>
void Gui::initGui()
{
	songsListWidget = new QListWidget();
	artistLineEdit = new QLineEdit();
	titleLineEdit = new QLineEdit();
	sourceLineEdit = new QLineEdit();

	addButton = new QPushButton("Add");
	deleteButton = new QPushButton("Delete");


	QVBoxLayout* mainLayout= new QVBoxLayout(this);
	mainLayout->addWidget(this->songsListWidget);

	QFormLayout* formLayout = new QFormLayout();

	formLayout->addRow("Artist", artistLineEdit);
	formLayout->addRow("Title", titleLineEdit);
	formLayout->addRow("Source", sourceLineEdit);

	mainLayout->addLayout(formLayout);

	QHBoxLayout* horizontalLayout = new QHBoxLayout();
	horizontalLayout->addWidget(addButton);
	horizontalLayout->addWidget(deleteButton);

	mainLayout->addLayout(horizontalLayout);

	populateSongsList();

	connectSignalsAndSlots();
}

void Gui::populateSongsList()
{
	songsListWidget->clear();
	for (Song currentSong : service.getAllSongs())
	{
		songsListWidget->addItem(QString::fromStdString(currentSong.getArtist() + "-" + currentSong.getTitle()));
	}
}
void Gui::connectSignalsAndSlots()
{
	QObject::connect(songsListWidget, &QListWidget::clicked, [this]() {

		int selectedIndex = getSelectedIndexFromSongsList();

		Song currentSong = service.getAllSongs()[selectedIndex];

		artistLineEdit->setText(QString::fromStdString(currentSong.getArtist()));
		titleLineEdit->setText(QString::fromStdString(currentSong.getTitle()));
		sourceLineEdit->setText(QString::fromStdString(currentSong.getSource()));
		});
	QObject::connect(addButton, &QPushButton::clicked, this,&Gui::addSong);
	QObject::connect(deleteButton, &QPushButton::clicked, this,&Gui::deleteSong);
}

int Gui::getSelectedIndexFromSongsList()
{
	QModelIndexList indexList = this->songsListWidget->selectionModel()->selectedIndexes();

	return (indexList.count() > 0) ? indexList[0].row() : -1;
}

void Gui::addSong()
{
	std::string artist = artistLineEdit->text().toStdString();
	std::string title = titleLineEdit->text().toStdString();
	std::string source = sourceLineEdit->text().toStdString();
	try {
		service.addSongToRepository(artist, title, 1, 1, source);
	}
	catch (DuplicateSongException& ex) {
		QMessageBox::critical(this, "Error", QString::fromStdString(ex.what()));
	}
	catch (SongException& ex) {
		QMessageBox::critical(this, "Error", QString::fromStdString(ex.getErrors()[0]));
	}
	this->populateSongsList();
}

void Gui::deleteSong()
{
	int selectedIndex = getSelectedIndexFromSongsList();
	if (selectedIndex == -1) {
		QMessageBox::critical(this, "Error", "No song selected!");
		return;
	}
	Song song = service.getAllSongs()[selectedIndex];
	service.removeSongFromRepository(song.getArtist(), song.getTitle());
	this->populateSongsList();
}

Gui::Gui(Service& serv):service(serv)
{
	this->initGui();
}
