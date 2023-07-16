#include "Doctor.h"

vector<string> Doctor::tokenize(const string& answer, char delimiter)
{
	vector<string> result;
	stringstream ss(answer);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Doctor& a)
{
	string line;
	getline(is, line);
	vector<string> tokens;
	tokens = Doctor::tokenize(line, ',');
	a.getName() = tokens[0];
	a.getSpecialization() = (tokens[1]);
	return is;
}

ostream& operator<<(ostream& os, Doctor& a)
{
	os << a.getName() << "," << a.getSpecialization() << "\n";
	return os;
}
