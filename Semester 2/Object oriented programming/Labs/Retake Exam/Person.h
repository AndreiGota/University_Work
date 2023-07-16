#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Person {
private:
	string name;
	bool status;
	int latitude, longitude;
public:
	Person(string _name, int _lat, int _long, bool s) :
		name(_name), latitude(_lat), longitude(_long), status(s) {

	}
	bool getStatus() {
		return this->status;
	}
	string getName() {
		return this->name;
	}
	int getLatitude() {
		return this->latitude;
	}
	int getLongitude() {
		return this->longitude;
	}
};