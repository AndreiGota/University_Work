#include "Controller.h"

void Controller::readCouriers()
{
	ifstream fin(this->courierFile);
	string line;
	while (getline(fin, line)) {
		string token;
		vector<string> data;
		stringstream ss(line);
		while (getline(ss, token, '|'))
			data.push_back(token);

		string token2;
		vector<string> data2;
		stringstream ss2(data[1]);
		while (getline(ss2, token2, ','))
			data2.push_back(token2);

		string token3;
		vector<string> data3;
		stringstream ss3(data[2]);
		while (getline(ss3, token3, ';'))
			data3.push_back(token3);

		Zone z(stoi(data3[0]), stoi(data3[1]), stoi(data3[2]));
		Courier c(data[0], data2, z);
		couriers.push_back(c);
	}
	fin.close();
}

void Controller::readPackages()
{
	ifstream fin(this->packageFile);
	string line;
	while (getline(fin, line)) {
		string token;
		vector<string> data;
		stringstream ss(line);
		while (getline(ss, token, '|'))
			data.push_back(token);

		string token2;
		vector<string> data2;
		stringstream ss2(data[1]);
		while (getline(ss2, token2, ','))
			data2.push_back(token2);
		Address a(data2[0], stoi(data2[1]));

		string token3;
		vector<string> data3;
		stringstream ss3(data[2]);
		while (getline(ss3, token3, ';'))
			data3.push_back(token3);
		Location loc(stoi(data3[0]), stoi(data3[1]));

		bool status = false;
		if (data[3] == "true")
			status = true;
		Package p(data[0], a, loc, status);
		packages.push_back(p);
	}
	fin.close();
}

void Controller::writePackagea()
{
	ofstream fout(this->packageFile);
	for (auto& it : packages)
		fout << it.toStringFile() << "\n";
}
