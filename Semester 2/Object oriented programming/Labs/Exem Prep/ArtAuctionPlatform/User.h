#pragma once
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

class User {
private:
	string name;
	int id;
	string type;
public:
	User(string name= "", int id = -1, string type = ""): name(name), id(id), type(type) {}
	string getName() { return this->name; }
	string getType() { return this->type; }
	int getId() { return this->id; }
};