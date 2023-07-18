#pragma once
#include "Observer.h"
#include "Subject.h"
#include "Item.h"
#include "User.h"

class Controller: public Subject {
private:
	vector<User> users;
	vector<Item> items;
	string userFile = "users.txt", itemFile = "items.txt";
public:
	Controller() {
		this->readUsersFromFile();
		this->readItemsFromFile();
	}
	void readUsersFromFile();
	void readItemsFromFile();
	void writeItemsToFile();
	void addItem(string name, string category, int currPrice);
	vector<User>& getAllUsers();
	vector<Item>& getAllItems();
	vector<Item> getAllItemsFromGivenCategory(string category);
	vector<string> getCategories();
};