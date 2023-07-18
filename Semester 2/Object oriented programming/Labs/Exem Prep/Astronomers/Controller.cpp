#include "Controller.h"

void Controller::readAstronomers()
{
	ifstream fin(this->astronomersFile);
	string line;
	while (getline(fin, line)) {
		vector<string> data;
		string token;
		stringstream ss(line);
		while (getline(ss, token, '|'))
			data.push_back(token);
		Astronomer a(data[0], data[1]);
		astronomers.push_back(a);
	}
	fin.close();
}

void Controller::readStars()
{
	ifstream fin(this->starsFile);
	string line;
	while (getline(fin, line)) {
		vector<string> data;
		string token;
		stringstream ss(line);
		while (getline(ss, token, '|'))
			data.push_back(token);
		Star s(data[0], data[1], stoi(data[2]), stoi(data[3]), stoi(data[4]));
		stars.push_back(s);
	}
	fin.close();
}

void Controller::writeStars()
{
	ofstream fout(this->starsFile);
	for (auto& it : stars)
		fout << it.toStringFile() << "\n";
	fout.close();
}
