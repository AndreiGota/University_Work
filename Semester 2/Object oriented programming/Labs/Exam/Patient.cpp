#include "Patient.h"

vector<string> Patient::tokenize(const string& answer, char delimiter)
{
	vector<string> result;
	stringstream ss(answer);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Patient& a)
{
	string line;
	getline(is, line);
	vector<string> tokens;
	tokens = Patient::tokenize(line, ',');
	a.getName() = tokens[0];
	a.getDiagnosis() = tokens[1];
	a.getSpecialization() = tokens[2];
	a.getCurrentDoctor() = tokens[3];
	a.getAdmissionDate() = tokens[4];
	return is;
}

ostream& operator<<(ostream& os, Patient& a)
{
	os << a.getName() << "," << a.getDiagnosis() << "," << a.getSpecialization() << "," << a.getCurrentDoctor() << "," << a.getAdmissionDate() << "\n";
	return os;
}
