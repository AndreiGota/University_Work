#include "CSVrepository.h"
#include <fstream>

CSVRepo::CSVRepo(const vector<DogObject>& adoption_list, const string& userFilename)
{
    this->adoptionList = adoption_list;
    this->userFilename = userFilename;
}

vector<DogObject>& CSVRepo::getAllUserRepo()
{
    return this->adoptionList;
}

int CSVRepo::getNumberElements()
{
    return this->adoptionList.size();
}

void CSVRepo::addUserRepo(const DogObject& dog)
{
    this->adoptionList.push_back(dog);
    this->writeToFile();
}

void CSVRepo::writeToFile()
{
    ofstream fout(this->userFilename);
    if (!this->adoptionList.empty()) {
        for (const DogObject& dog : this->adoptionList)
            fout << dog << endl;
    }
    fout.close();
}

string& CSVRepo::getFilename()
{
    return this->userFilename;
}

CSVRepo::~CSVRepo() = default;
