#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class Astronomer {
private:
	string astronomer, constellation;
public:
	Astronomer(string astronomer = "", string constellation = ""): astronomer(astronomer), constellation(constellation) {}
	string getAstronomerName() { return this->astronomer; }
	string getConstellation() { return this->constellation; }
};