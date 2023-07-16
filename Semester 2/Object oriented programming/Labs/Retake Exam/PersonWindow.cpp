#include "PersonWindow.h"
#include <qmessagebox.h>
#include <cmath>

PersonWindow::PersonWindow(Controller& c, Person p, QWidget *parent)
    :controller(c), person(p), QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle(QString::fromStdString(person.getName() + "-" + to_string(person.getLatitude()) + "," + to_string(person.getLongitude())));
    populateEventList();
    QObject::connect(ui.addButton, &QPushButton::clicked, this, &PersonWindow::addEventGUI);
    connect(ui.checkBox, &QCheckBox::toggled, this, &PersonWindow::showSpecificEvents);

}

PersonWindow::~PersonWindow()
{}

void PersonWindow::populateEventList()
{
    ui.eventListWidget->clear();
    for (auto& it : controller.getEvents()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(it.toString()));
        QBrush brush(Qt::green);
        if (person.getStatus() == true && it.getOrganiser() == person.getName())
            item->setBackground(brush);
        ui.eventListWidget->addItem(item);
    }
}

void PersonWindow::addEventGUI()
{
    if (person.getStatus() == false) {
        QMessageBox::critical(0, "Error", "can't organise events!");
        return;
    }
    string name = ui.nameLineEdit->text().toStdString();
    string description = ui.descriptionLineEdit->text().toStdString();
    string date_string = ui.dateLineEdit->text().toStdString();
    int latitude = ui.latitudeLineEdit->text().toInt();
    int longitude = ui.longitudeLineEdit->text().toInt();
    vector<string> date_data;
    string token;
    stringstream sss(date_string);
    while (getline(sss, token, '.'))
        date_data.push_back(token);
    Date dd(stoi(date_data[0]), stoi(date_data[1]), stoi(date_data[2]));
    Location loc(latitude, longitude);
    Event eventX(person.getName(), name, description, loc, dd);
    

    for (auto& it : controller.getEvents()) {
        int nr1 = it.getLocation().latitude;
        int nr2 = it.getLocation().longitude;
        if (it.getName() == name && nr1 == latitude && nr2 == longitude) {
            QMessageBox::critical(0, "Error", "event already exists!");
            return;
        }
    }
    this->controller.addEvent(eventX);
    this->controller.notify();
    this->controller.writeEvent();
}

void PersonWindow::update()
{
    this->populateEventList();
}

void PersonWindow::showSpecificEvents()
{
    bool isChecked = ui.checkBox->isChecked();
    if (isChecked) {
        ui.eventListWidget->clear();
        for (auto& it : controller.getEvents()) {
            int x1 = it.getLocation().latitude;
            int y1 = it.getLocation().longitude;
            int x2 = person.getLatitude();
            int y2 = person.getLongitude();
            int rez = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            if (rez <= 5) {
                QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(it.toString()));
                ui.eventListWidget->addItem(item);
            }
        }
    }
    else {
        populateEventList();
    }
}
