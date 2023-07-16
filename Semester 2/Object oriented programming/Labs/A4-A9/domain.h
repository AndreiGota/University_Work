#pragma once
#include <string>
using namespace std;

class DogObject {
private:
	string breed;
	string name;
	int age;
	string photo;
public:

	//Constructor for DogObject class
	explicit DogObject(string breed = "", string name = "", int age = 0, string photo = "");


	//Getters
	string getBreed() const;
	string getName() const;
	int getAge() const;
	string getPhoto() const;

	//toString() returns a formatted string containing the information inside a DogObject, for easy printing.
	string toString() const;

	bool operator==(const DogObject& dogToCheck) const;

	friend istream& operator>>(istream& inputStream, DogObject& dog);

	friend ostream& operator<<(ostream& outputStream, const DogObject& dogOutput);

	//Destructor
	~DogObject();
};