#include <QWidget>
#include "ADMINservice.h"
#include <QLabel>
#include <QPushButton>
#include "USERservice.h"
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include "validators.h"

class GUI : public QWidget {
private:
	AdministratorService& adminService;
	UserService& userService;
	DogObjectValidator& validator;
	void initGUI();
	QLabel* titleWidget;
	QPushButton* adminButton;
	QPushButton* userButton;
	void showAdminMode();
	void showUserMode();
	void connectSignalsAndSlots();
public:
	GUI(AdministratorService& admin_service, UserService& user_service, DogObjectValidator& _validator);
	~GUI() override;
};

class AdminModeGUI : public QWidget {
private:
	AdministratorService& adminService;
	DogObjectValidator& validator;
	void initAdminModeGUI();
	QLabel* titleWidget;
	QListWidget* dogsListWidget;
	QLineEdit* nameLineEdit, * breedLineEdit, * ageLineEdit, * photoLineEdit;
	QPushButton* addButton, * deleteButton, * updateButton;

	void populateList();
	void connectSignalsAndSlots();
	int getSelectedIndex() const;
	void addDog();
	void deleteDog();
	void updateDog();
public:
	AdminModeGUI(QWidget* parent, AdministratorService& admin_service, DogObjectValidator& _validator);
	~AdminModeGUI() override;
};

class UserModeGUI : public QWidget {
private:
	AdministratorService& adminService;
	UserService& userService;
	DogObjectValidator& validator;
	void initUserModeGUI();
	QLabel* titleWidget;
	QListWidget* dogsListWidget, * adoptionListWidget;
	QLineEdit* nameLineEdit, * breedLineEdit, * ageLineEdit, * photoLineEdit, * breedFilterLineEdit, * ageFilterLineEdit;
	QPushButton* addButton, * filterButton, * openListButton;
	QRadioButton* csvButton, * htmlButton;
	bool repoTypeSelected;
	bool filtered;
	void populateDogList();
	void populateAdoptionList();
	void connectSignalsAndSlots();
	int getSelectedIndex() const;
	void addDogToAdoptionList();
	void filterDogs();
public:
	UserModeGUI(QWidget* parent, AdministratorService& admin_service, UserService& user_service, DogObjectValidator& _validator);
	~UserModeGUI() override;
};
