#include "SongWindow.h"

SongWindow::SongWindow(tableModel* songModel,QWidget *parent)
    : songModel(songModel), QMainWindow(parent)
{
    ui.setupUi(this);
    ui.songTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui.songTableView->setModel(this->songModel);
    ui.songTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //connect(ui.songTableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &SongWindow::onSongSelectionChanged);
    connect(ui.songTableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &SongWindow::onSongSelectionChanged);
    //QObject::connect(this->acceptIdeaButton, &QPushButton::clicked, this, &IdeasTable::acceptIdea);
    connect(ui.updateButton, &QPushButton::clicked, this, &SongWindow::updateSongGUI);
}

SongWindow::~SongWindow()
{}

void SongWindow::onSongSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected); // To suppress the unused parameter warning

    if (selected.indexes().isEmpty()) {
        // No selection, clear the QLineEdit widgets
        ui.titleLineEdit->clear();
        ui.rankLineEdit->clear();
        return;
    }

    // Get the selected row from the first selected index
    int row = selected.indexes().first().row();
    Song& selectedSong = songModel->getControllerReference().getSongs().at(row);

    // Populate the title and rank QLineEdit widgets with the selected song's data
    ui.titleLineEdit->setText(QString::fromStdString(selectedSong.getTitle()));
    ui.rankLineEdit->setText(QString::number(selectedSong.getRank()));
    ui.rankSlider->setRange(0, 10);
    ui.rankSlider->setValue(selectedSong.getRank());
}

void SongWindow::updateSongGUI()
{
    int sliderValue = ui.rankSlider->value();
    string title = ui.titleLineEdit->text().toStdString();
    int row = this->ui.songTableView->currentIndex().row();
    this->songModel->updateSongModel(row, title, sliderValue);
}


