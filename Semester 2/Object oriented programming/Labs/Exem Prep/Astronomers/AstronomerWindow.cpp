#include "AstronomerWindow.h"
#include <qmessagebox.h>

AstronomerWindow::AstronomerWindow(starModel* m, Astronomer a, QWidget *parent)
    : QMainWindow(parent), model(m), astronomer(a)
{
    ui.setupUi(this);

    ui.starTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui.starTableView->setModel(model);
    //QObject::connect(&ui.searchLineEdit, &QLineEdit::textChanged, this, &AstronomerWindow::searchStars);
    QObject::connect(ui.lineEdit, &QLineEdit::textChanged, this, [=](const QString& text) {
        ui.starListWidget->clear();
        QString searched_word = text;
        for (auto& it : this->model->getControllerReference().getStars()) {
            QString name = QString::fromStdString(it.getName());
            if (name.contains(searched_word, Qt::CaseInsensitive)) {
                QListWidgetItem* item = new QListWidgetItem(name);
                ui.starListWidget->addItem(item);
            }
        }
        });
    QObject::connect(ui.addButton, &QPushButton::clicked, this, &AstronomerWindow::addStarGUI);
}

AstronomerWindow::~AstronomerWindow()
{}

void AstronomerWindow::addStarGUI()
{
    string name = ui.nameLineEdit->text().toStdString();
    int ra = ui.raLineEdit->text().toInt();
    int dec = ui.decLineEdit->text().toInt();
    int diameter = ui.diameterLineEdit->text().toInt();
    string constellation = astronomer.getConstellation();

    if (name.empty()) {
        QMessageBox::critical(0, "Error", "name is empty");
        return;
    }
    Controller& con = model->getControllerReference();
    for (auto& it : con.getStars()) {
        if (it.getName() == name) {
            QMessageBox::critical(0, "Error", "name already exists");
            return;
        }
    }
    Star star(name, constellation, ra, dec, diameter);
    model->addStarModel(star);
}

