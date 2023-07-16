#include <QVBoxLayout>
#include <QFormLayout>
#include <QErrorMessage>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "GUI.h"

GUI::GUI(AdministratorService& admin_service, UserService& user_service, DogObjectValidator& _validator) : adminService{ admin_service }, userService{ user_service }, validator{ _validator } {
    this->titleWidget = new QLabel(this);
    this->adminButton = new QPushButton(this);
    this->userButton = new QPushButton(this);
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#FF9933>Welcome to the Dog Shelter App! <br> Select your mode!</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(12);
    titleFont.setWeight(QFont::Bold);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);

    this->adminButton->setText("Admin mode");
    this->adminButton->setFont(titleFont);
    layout->addWidget(this->adminButton);
    this->userButton->setText("User mode");
    this->userButton->setFont(titleFont);
    layout->addWidget(this->userButton);
    this->setLayout(layout);
    this->setStyleSheet("background-color:#3399FF");
}

GUI::~GUI() = default;

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUI::showAdminMode);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &GUI::showUserMode);
}

void GUI::showAdminMode() {
    auto* admin = new AdminModeGUI(this, this->adminService, this->validator);
    admin->show();
}

AdminModeGUI::AdminModeGUI(QWidget* parent, AdministratorService& admin_service, DogObjectValidator& _validator) : adminService{ admin_service }, validator{ _validator } {
    this->titleWidget = new QLabel(this);
    this->dogsListWidget = new QListWidget{};
    this->nameLineEdit = new QLineEdit{};
    this->breedLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photoLineEdit = new QLineEdit{};
    this->addButton = new QPushButton("Add");
    this->deleteButton = new QPushButton("Delete");
    this->updateButton = new QPushButton("Update");
    setParent(parent);
    setWindowFlag(Qt::Window);
    this->initAdminModeGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdminModeGUI::initAdminModeGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#FF9933>ADMIN MODE</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(12);
    titleFont.setWeight(QFont::Bold);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);

    layout->addWidget(this->dogsListWidget);

    auto* dogDetailsLayout = new QFormLayout{};
    dogDetailsLayout->addRow("Name", this->nameLineEdit);
    dogDetailsLayout->addRow("Breed", this->breedLineEdit);
    dogDetailsLayout->addRow("Age", this->ageLineEdit);
    dogDetailsLayout->addRow("Photo Link", this->photoLineEdit);
    layout->addLayout(dogDetailsLayout);

    auto* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateButton, 1, 0);
    layout->addLayout(buttonsLayout);
}

void AdminModeGUI::populateList() {
    this->dogsListWidget->clear();
    vector<DogObject> allDogs = this->adminService.getAllAdminService();
    for (DogObject& dog : allDogs) 
        this->dogsListWidget->addItem(QString::fromStdString(dog.toString()));
    
}

void AdminModeGUI::connectSignalsAndSlots() {
    QObject::connect(this->dogsListWidget, &QListWidget::itemSelectionChanged, [this]() {
        int selectedIndex = this->getSelectedIndex();
        if (selectedIndex < 0)
            return;
        DogObject dog = this->adminService.getAllAdminService()[selectedIndex];
        this->nameLineEdit->setText(QString::fromStdString(dog.getName()));
        this->breedLineEdit->setText(QString::fromStdString(dog.getBreed()));
        this->ageLineEdit->setText(QString::fromStdString(to_string(dog.getAge())));
        this->photoLineEdit->setText(QString::fromStdString(dog.getPhoto()));
        });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminModeGUI::addDog);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminModeGUI::deleteDog);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminModeGUI::updateDog);
}

void AdminModeGUI::addDog() {
    string breed = this->breedLineEdit->text().toStdString();
    string name = this->nameLineEdit->text().toStdString();
    string age_s = this->ageLineEdit->text().toStdString();
    string photo = this->photoLineEdit->text().toStdString();
    int age;
    try {
        this->validator.validateBreed(breed);
        this->validator.validateName(name);
        this->validator.validateAgeString(age_s);
        age = stoi(age_s);
        this->validator.validateAge(age);
        this->validator.validatePhoto(photo);
        this->adminService.addAdminService(breed, name, age, photo);
        this->populateList();
    }
    catch (ValidationException& ve) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(ve.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    }
    catch (AdminRepoException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at adding dog!");
        error->exec();
    }
}

void AdminModeGUI::deleteDog() {
    try {
        string name = this->nameLineEdit->text().toStdString();
        string breed = this->breedLineEdit->text().toStdString();
        this->validator.validateName(name);
        this->validator.validateBreed(breed);
        this->adminService.deleteAdminService(name, breed);
        this->populateList();
    }
    catch (ValidationException& ve) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(ve.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    }
    catch (AdminRepoException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at deleting dog!");
        error->exec();
    }
}

void AdminModeGUI::updateDog() {
    int index = this->getSelectedIndex();
    try {
        if (index < 0) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText("No dog selected!");
            error->setWindowTitle("Selection error!");
            error->exec();
        }
        else {
            string old_name = this->adminService.getAllAdminService()[index].getName();
            string old_breed = this->adminService.getAllAdminService()[index].getBreed();
            string new_name = this->nameLineEdit->text().toStdString();
            string new_breed = this->breedLineEdit->text().toStdString();
            string new_age_s = this->ageLineEdit->text().toStdString();
            int new_age;
            string new_photo = this->photoLineEdit->text().toStdString();
            this->validator.validateName(old_name);
            this->validator.validateBreed(old_breed);
            this->validator.validateName(new_name);
            this->validator.validateBreed(new_breed);
            this->validator.validateAgeString(new_age_s);
            new_age = stoi(new_age_s);
            this->validator.validateAge(new_age);
            this->validator.validatePhoto(new_photo);
            this->adminService.updateAdminService(old_name, old_breed, new_breed, new_name, new_age, new_photo);
            this->populateList();
        }
    }
    catch (ValidationException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    }
    catch (AdminRepoException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at deleting dog!");
        error->exec();
    }
}

int AdminModeGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->dogsListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()) {
        this->nameLineEdit->clear();
        this->breedLineEdit->clear();
        this->ageLineEdit->clear();
        this->photoLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

AdminModeGUI::~AdminModeGUI() = default;

void GUI::showUserMode() {
    auto* user = new UserModeGUI(this, this->adminService, this->userService, this->validator);
    user->show();
}

UserModeGUI::UserModeGUI(QWidget* parent, AdministratorService& admin_service, UserService& user_service, DogObjectValidator& _validator) : adminService{ admin_service }, userService{ user_service }, validator{ _validator } {
    this->titleWidget = new QLabel(this);
    this->dogsListWidget = new QListWidget{};
    this->adoptionListWidget = new QListWidget{};
    this->nameLineEdit = new QLineEdit{};
    this->breedLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photoLineEdit = new QLineEdit{};
    this->breedFilterLineEdit = new QLineEdit{};
    this->ageFilterLineEdit = new QLineEdit{};
    this->addButton = new QPushButton("Add to the adoption list");
    this->filterButton = new QPushButton("Filter");
    this->openListButton = new QPushButton("Open file");
    this->csvButton = new QRadioButton("CSV");
    this->htmlButton = new QRadioButton("HTML");
    this->repoTypeSelected = false;
    this->filtered = false;
    setParent(parent);
    setWindowFlag(Qt::Window);
    this->initUserModeGUI();
    this->populateDogList();
    this->connectSignalsAndSlots();
}

void UserModeGUI::initUserModeGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#FF9933>USER MODE <br> Select the type of file you want for saving your adopted dogs!</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(12);
    titleFont.setWeight(QFont::Bold);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);

    auto* radioButtonsLayout = new QGridLayout(this);
    radioButtonsLayout->addWidget(this->csvButton, 0, 0);
    radioButtonsLayout->addWidget(this->htmlButton, 1, 0);
    radioButtonsLayout->addWidget(this->openListButton, 0, 1);
    layout->addLayout(radioButtonsLayout);

    auto* listLayout = new QGridLayout(this);
    listLayout->addWidget(this->dogsListWidget, 0, 0);
    listLayout->addWidget(this->adoptionListWidget, 0, 1);
    layout->addLayout(listLayout);

    auto* dogDetailsLayout = new QFormLayout{};
    dogDetailsLayout->addRow("Name", this->nameLineEdit);
    dogDetailsLayout->addRow("Breed", this->breedLineEdit);
    dogDetailsLayout->addRow("Age", this->ageLineEdit);
    dogDetailsLayout->addRow("Link", this->photoLineEdit);
    dogDetailsLayout->addRow(this->addButton);
    layout->addLayout(dogDetailsLayout);


    auto* filterTitle = new QLabel("<p style='text-align:center'><font color=#FF9933><br>Filter the available dogs by breed and age</font></p>");
    QFont filterFont = filterTitle->font();
    filterFont.setItalic(true);
    filterFont.setPointSize(12);
    filterFont.setWeight(QFont::Bold);
    filterTitle->setFont(filterFont);
    layout->addWidget(filterTitle);

    auto* filterDetailsLayout = new QFormLayout{};
    filterDetailsLayout->addRow("Breed", this->breedFilterLineEdit);
    filterDetailsLayout->addRow("Age", this->ageFilterLineEdit);
    filterDetailsLayout->addRow(this->filterButton);
    layout->addLayout(filterDetailsLayout);
}

void UserModeGUI::populateDogList() {
    this->dogsListWidget->clear();
    vector<DogObject> allDogs = this->adminService.getAllAdminService();
    for (DogObject& dog : allDogs) {
        this->dogsListWidget->addItem(QString::fromStdString(dog.toString()));
    }
}

void UserModeGUI::connectSignalsAndSlots() {
    QObject::connect(this->dogsListWidget, &QListWidget::itemClicked, [this]() {
        string dog_format = this->dogsListWidget->selectedItems().at(0)->text().toStdString();
        int pos = dog_format.find(" ");
        string dog_name = dog_format.substr(0, pos);
        int index = this->adminService.findByNameService(dog_name);
        DogObject dog = this->adminService.getAllAdminService()[index];
        this->nameLineEdit->setText(QString::fromStdString(dog.getName()));
        this->breedLineEdit->setText(QString::fromStdString(dog.getBreed()));
        this->ageLineEdit->setText(QString::fromStdString(to_string(dog.getAge())));
        this->photoLineEdit->setText(QString::fromStdString(dog.getPhoto()));
        string link = string("start ").append(dog.getPhoto());
        system(link.c_str());
        });

    QObject::connect(this->csvButton, &QRadioButton::clicked, [this]() {
        this->userService.repositoryType("csv");
        this->repoTypeSelected = true;
        });

    QObject::connect(this->htmlButton, &QRadioButton::clicked, [this]() {
        this->userService.repositoryType("html");
        this->repoTypeSelected = true;
        });

    QObject::connect(this->openListButton, &QPushButton::clicked, [this]() {
        if (!this->repoTypeSelected) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Warning);
            error->setText("Please select the type of file you want!");
            error->setWindowTitle("File type warning!");
            error->exec();
        }
        else {
            string link = string("start ").append(this->userService.getFileUserService());
            system(link.c_str());
        }
        });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &UserModeGUI::addDogToAdoptionList);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &UserModeGUI::filterDogs);
}

int UserModeGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->dogsListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()) {
        this->nameLineEdit->clear();
        this->breedLineEdit->clear();
        this->ageLineEdit->clear();
        this->photoLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void UserModeGUI::populateAdoptionList() {
    this->adoptionListWidget->clear();
    vector<DogObject> allDogs = this->userService.getAllUserService();
    for (DogObject& dog : allDogs)
        this->adoptionListWidget->addItem(QString::fromStdString(dog.toString()));
}

void UserModeGUI::addDogToAdoptionList() {
    if (!this->repoTypeSelected) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Warning);
        error->setText("Please select the type of file you want!");
        error->setWindowTitle("File type warning!");
        error->exec();
    }
    else {
        string breed = this->breedLineEdit->text().toStdString();
        string name = this->nameLineEdit->text().toStdString();
        string age_string = this->ageLineEdit->text().toStdString();
        string photo = this->photoLineEdit->text().toStdString();
        int age;
        try {
            this->validator.validateBreed(breed);
            this->validator.validateName(name);
            this->validator.validateAgeString(age_string);
            age = stoi(age_string);
            this->validator.validateAge(age);
            this->validator.validatePhoto(photo);
            DogObject dog = DogObject(breed, name, age, photo);
            this->userService.addUserService(dog);
            if (!this->filtered)
                this->populateDogList();
            else
                this->adoptionListWidget->addItem(this->dogsListWidget->takeItem(this->getSelectedIndex()));
            this->populateAdoptionList();
        }
        catch (ValidationException& exc) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(exc.what());
            error->setWindowTitle("Invalid input!");
            error->exec();
        }
        catch (AdminRepoException& re) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(re.what());
            error->setWindowTitle("Error at adding dog!");
            error->exec();
        }
    }
}

void UserModeGUI::filterDogs() {
    try {
        string breed_filter = this->breedFilterLineEdit->text().toStdString();
        string age_filter_string = this->ageFilterLineEdit->text().toStdString();
        int age_filter;
        if (breed_filter.empty() && age_filter_string.empty()) {
            this->filtered = false;
            this->populateDogList();
        }
        else {
            this->validator.validateString(breed_filter);
            this->validator.validateAgeString(age_filter_string);
            age_filter = stoi(age_filter_string);
            this->validator.validateAge(age_filter);
            vector<DogObject> validDogs;
            this->adminService.getFiltered(validDogs, breed_filter, age_filter);
            if (validDogs.empty()) {
                string error;
                error += string("The list of valid dogs is empty!");
                if (!error.empty())
                    throw UserRepoException(error);
            }
            else {
                this->filtered = true;
                this->dogsListWidget->clear();
                for (DogObject& dog : validDogs)
                    this->dogsListWidget->addItem(QString::fromStdString(dog.toString()));
            }
        }
    }
    catch (ValidationException& ve) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(ve.what());
        error->setWindowTitle("Validation error!");
        error->exec();
    }
    catch (UserRepoException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Filter error!");
        error->exec();
    }
}

UserModeGUI::~UserModeGUI() = default;
