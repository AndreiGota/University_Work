#include "CourierWindow.h"
#include <qmessagebox.h>

CourierWindow::CourierWindow(Controller& c, Courier cou, QWidget *parent)
    : QMainWindow(parent), controller(c), courier(cou)
{
    ui.setupUi(this);
    setWindowTitle(QString::fromStdString(courier.getName()));
    ui.zoneLabel->setText(QString::fromStdString((courier.getZone().toStringZone())));
    populateUndeliveredPackagesList();
    for (auto& it : courier.getStreets())
        ui.streetsComboBox->addItem(QString::fromStdString(it));
    QObject::connect(ui.filterPushButton, &QPushButton::clicked, this, &CourierWindow::showSpecificStreets);
    QObject::connect(ui.deliverButton, &QPushButton::clicked, this, &CourierWindow::deliverPackage);
}

CourierWindow::~CourierWindow()
{}

void CourierWindow::populateUndeliveredPackagesList()
{
    ui.undeliveredPackagesList->clear();
    for (auto& it : controller.getPackages()) {
        bool must_add = false;
        for (auto& jt : courier.getStreets())
            if (it.getAddres().getStreet() == jt && it.getDeliveryStatus() == false)
                must_add = true;
        if (must_add) {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(it.toStringFile()));
            ui.undeliveredPackagesList->addItem(item);
        }
    }
}

void CourierWindow::showSpecificStreets()
{
    QString currentItem = ui.streetsComboBox->currentText();
    string curr_street = currentItem.toStdString();
    ui.undeliveredPackagesList->clear();
    for (auto& it : controller.getPackages()) {
        if (it.getAddres().getStreet() == curr_street) {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(it.toStringFile()));
            ui.undeliveredPackagesList->addItem(item);
        }
    }
}

void CourierWindow::update()
{
    this->populateUndeliveredPackagesList();
}

void CourierWindow::deliverPackage()
{
    /*ui.undeliveredPackagesList->clear();
    QModelIndex selectedIndex = ui.undeliveredPackagesList->currentIndex();
    if (selectedIndex.isValid()) {
        QMessageBox::critical(0, "Error", "No package selected");
        return;
    }
    QString undeliveredPackage = ui.undeliveredPackagesList->item(selectedIndex.row())->text();*/
    QModelIndex selectedIndex = ui.undeliveredPackagesList->currentIndex();
    if (!selectedIndex.isValid()) {
        QMessageBox::critical(0, "Error", "No package selected");
        return;
    }
    QString undeliveredPackage = ui.undeliveredPackagesList->item(selectedIndex.row())->text();
    // Rest of the code...
    for (auto& it : controller.getPackages()) {
        QString x = QString::fromStdString(it.toStringFile());
        if (x == undeliveredPackage) {
            it.setStatus();
            controller.notify();
            controller.writePackagea();
        }
    }
}
