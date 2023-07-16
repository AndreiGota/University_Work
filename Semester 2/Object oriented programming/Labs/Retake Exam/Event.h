#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Date {
public:
	int day, month, year;
	Date(int day = 0, int month = 0, int year = 0):
		day(day), month(month), year(year) {}
	string toStringDate() {
		return to_string(day) + "." + to_string(month) + "." + to_string(year);
	}
};

class Location {
public:
	int latitude, longitude;
	Location(int latitude = 0, int longitude = 0):
		latitude(latitude), longitude(longitude) {}
	string toStringLocation() {
		return to_string(latitude) + "," + to_string(longitude);
	}
};
//Henry|Jojo|tur rir|5,3|3.5.2023
class Event {
private:
	string organiser, name, description;
	Location location;
	Date date;
public:
	Event(string organiser = "", string name = "", string description = "", Location loc = Location(), Date date = Date()):
		organiser(organiser), name(name), description(description), location(loc), date(date) {}
	string getOrganiser() { return this->organiser; }
	string getName() { return this->name; }
	string getDescription() { return this->description; }
	Location getLocation() { return this->location; }
	Date getDate() { return this->date; }
	string toStringFile() {
		string x = "";
		x += this->organiser + "|" + this->name + "|" + this->description + "|";
		x += this->location.toStringLocation() + "|";
		x += this->date.toStringDate();
		return x;
	}
	string toString() {
		string x = "";
		x += this->organiser + "|" + this->name + "|";
		x += this->location.toStringLocation() + "|";
		x += this->date.toStringDate();
		return x;
	}
};