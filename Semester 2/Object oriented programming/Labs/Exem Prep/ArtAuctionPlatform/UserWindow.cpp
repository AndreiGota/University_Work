#include "UserWindow.h"
#include <qmessagebox.h>


UserWindow::UserWindow(Controller& controller, User u, QWidget* parent):
    controller(controller), user(u), QMainWindow(parent)
{
    ui.setupUi(this);

    //setWindowTitle(QString::fromStdString(this->doctor.getName() + " | Specialisation: " + this->doctor.getSpecialisation()));
    setWindowTitle(QString::fromStdString(this->user.getName() + " " + this->user.getType()));
    this->populateList();
    for (int i = 0; i < this->controller.getCategories().size(); i++)
        ui.comboBox->addItem(QString::fromStdString(this->controller.getCategories()[i]));
    QObject::connect(ui.getCategoryButton, &QPushButton::clicked, this, &UserWindow::displaySpecificItems);
    QObject::connect(ui.addItemButton, &QPushButton::clicked, this, &UserWindow::addItemGUI);
    //connect(ui.songTableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &SongWindow::onSongSelectionChanged);
    connect(ui.itemsListWidget->selectionModel(), &QItemSelectionModel::selectionChanged, this, &UserWindow::onSongSelectionChanged);
}

UserWindow::~UserWindow()
{}

void UserWindow::update()
{
    this->populateList();
}

void UserWindow::populateList()
{
    this->ui.itemsListWidget->clear();

    for (auto& it : controller.getAllItems()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(it.toString()));
        ui.itemsListWidget->addItem(item);
    }
}

void UserWindow::displaySpecificItems()
{
    this->ui.itemsGivenCategory->clear();
    QString currentItem = ui.comboBox->currentText();
    string curr_category = currentItem.toStdString();
    for (auto& it: this->controller.getAllItemsFromGivenCategory(curr_category)) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(it.toString()));
        ui.itemsGivenCategory->addItem(item);
    }
}

void UserWindow::addItemGUI()
{
    QString windowTitle = this->windowTitle();
    string d = windowTitle.toStdString();
    if (d.find("Administrator") == string::npos) {
        QMessageBox::critical(0, "Error", "Collectors can't add items!");
        return;
    }

    string name = ui.nameLineEdit->text().toStdString();
    string category = ui.categoryLineEdit->text().toStdString();
    int curr_price = ui.priceLineEdit->text().toInt();
    if (name.empty()) {
        QMessageBox::critical(0, "Error", "Name can't be empty!");
        return;
    }
    if (curr_price <= 0) {
        QMessageBox::critical(0, "Error", "Price must be greater than 0!");
        return;
    }
    this->controller.addItem(name, category, curr_price);
    this->controller.notify();
    this->controller.writeItemsToFile();
    //this->populateList();
}

void UserWindow::onSongSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    /*
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
    */
    Q_UNUSED(deselected);

    if (selected.indexes().isEmpty()) {
        ui.offersListWidget->clear();
        return;
    }
    ui.offersListWidget->clear();
    int index = selected.indexes().first().row();
    Item& selectedItem = this->controller.getAllItems()[index];
    for (auto& it : selectedItem.getOffers()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(it.toStringOffer()));
        ui.offersListWidget->addItem(item);
    }
    //QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(selectedItem.toString()));
    //ui.offersListWidget->addItem(item);
}

