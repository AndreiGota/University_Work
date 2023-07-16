#include "Controller.h"

void Controller::readPerson()
{
	////Andy|6,4|true
	ifstream fin(this->personFile);
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
		int lat = stoi(data2[0]);
		int longi = stoi(data2[1]);

		Location loc(lat, longi);

		bool status_file = false;
		if (data[2] == "true")
			status_file = true;
		
		Person p(data[0], lat, longi, status_file);
		persons.push_back(p);

	}
}

////Henry|Jojo|tur rir|5,3|3.5.2023
void Controller::readEvent()
{
	ifstream fin(this->eventFile);
	string line;
	while (getline(fin, line)) {
		string token;
		vector<string> data;
		stringstream ss(line);
		while (getline(ss, token, '|'))
			data.push_back(token);

		string token2;
		vector<string> data2;
		stringstream ss2(data[3]);
		while (getline(ss2, token2, ','))
			data2.push_back(token2);
		Location loc(stoi(data2[0]), stoi(data2[1]));

		string token3;
		vector<string> data3;
		stringstream ss3(data[4]);
		while (getline(ss3, token3, '.'))
			data3.push_back(token3);
		Date d(stoi(data3[0]), stoi(data3[1]), stoi(data3[2]));
		Event e(data[0], data[1], data[2], loc, d);
		events.push_back(e);
	}
}

void Controller::writeEvent()
{
	ofstream fout(this->eventFile);
	for (auto& it : events)
		fout << it.toStringFile() << "\n";
}

vector<Person>& Controller::getPersons()
{
	return this->persons;
}

vector<Event>& Controller::getEvents()
{
    int n = events.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            Date d1 = events[j].getDate();
            Date d2 = events[j + 1].getDate();
            if (d1.year > d2.year || (d1.year == d2.year && d1.month > d2.month) ||
                (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)) {
                swap(events[j], events[j + 1]);
            }
        }
    }
    return events;
}
