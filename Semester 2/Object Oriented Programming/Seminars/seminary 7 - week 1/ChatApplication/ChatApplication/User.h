#pragma once
#include <string>

class User
{
private: 
	std::string uniqueUserName;
	std::string name;

public:
	User(const std::string& id, const std::string& n) : uniqueUserName{ id }, name{ n } {}
	std::string getUniqueUserName() const { return this->uniqueUserName; }
	std::string getName() const { return this->name; }
	bool  operator==(const User& u) { return this->uniqueUserName == u.uniqueUserName; }
};