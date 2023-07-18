#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Zone {
private:
	int coordX, coordY, radius;
public:
	Zone(int coordX = 0, int coordY = 0, int radius = 0):
		coordX(coordX), coordY(coordY), radius(radius) {}
	int getCoordX() { return this->coordX; }
	int getCoordY() { return this->coordY; }
	int getRadius() { return this->radius; }
	string toStringZone() {
		return to_string(coordX) + ";" + to_string(coordY) + ";" + to_string(radius);
	}
};

class Courier {
private:
	string name;
	vector<string> streets;
	Zone zone;
public:
	Courier(string _name = "", vector<string> _streets = {}, Zone _zone = Zone()) :
		name(_name), streets(_streets), zone(_zone) {}
	string getName() { return this->name; }
	vector<string>& getStreets() { return this->streets; }
	Zone getZone() { return this->zone; }

	string toStringFile() {
		string x = this->name + "|";
		for (auto& it : streets)
			x += it + ",";
		x.pop_back();
		x += "|";
		x += zone.toStringZone();
		return x;
	}
};