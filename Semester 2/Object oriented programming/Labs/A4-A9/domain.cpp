#include "domain.h"
#include <vector>
#include <sstream>
#include <utility>

DogObject::DogObject(string breed, string name, int age, string photo)
{
	if (age < 0) {
		throw "Age can't be smaller than 0!";
	}
	this->breed = move(breed);
	this->name = move(name);
	this->age = age;
	this->photo = photo;
}

string DogObject::getBreed() const
{
	return this->breed;
}

string DogObject::getName() const
{
	return this->name;
}

int DogObject::getAge() const
{
	return this->age;
}

string DogObject::getPhoto() const
{
	return this->photo;
}

string DogObject::toString() const
{
	return this->name + " " + this->breed + " " + to_string(this->age);
}

vector<string> tokenize(const string& dogStr, char delimiter)
{
	vector<string> result;
	stringstream ss(dogStr);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

bool DogObject::operator==(const DogObject& dogToCheck) const
{
	return this->name == dogToCheck.name && this->breed == dogToCheck.breed;
}

DogObject::~DogObject() = default;

istream& operator>>(istream& inputStream, DogObject& dog)
{
	string line;
	getline(inputStream, line);
	vector<string> tokens;
	if (line.empty())
		return inputStream;
	tokens = tokenize(line, ',');
	dog.breed = tokens[0];
	dog.name = tokens[1];
	dog.age = stoi(tokens[2]);
	dog.photo = tokens[3];
	return inputStream;
}

ostream& operator<<(ostream& outputStream, const DogObject& dogOutput)
{
	outputStream << dogOutput.breed << "," << dogOutput.name << "," << to_string(dogOutput.age) << "," << dogOutput.photo;
	return outputStream;
}
