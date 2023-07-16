#include "HTMLrepository.h"
#include <fstream>

HTMLRepo::HTMLRepo(const vector<DogObject>& adoption_list, const string& userFilename)
{
    this->adoptionList = adoption_list;
    this->userFilename = userFilename;
}

vector<DogObject>& HTMLRepo::getAllUserRepo()
{
    return this->adoptionList;
}

int HTMLRepo::getNumberElements()
{
    return this->adoptionList.size();
}

void HTMLRepo::addUserRepo(const DogObject& dog)
{
    this->adoptionList.push_back(dog);
    this->writeToFile();
}

void HTMLRepo::writeToFile()
{
    std::ofstream fout(this->userFilename);
    fout << "<!DOCTYPE html>\n<html><head><title>Adoption List</title></head><body>\n";
    fout << "<table border=\"1\">\n";
    fout << "<tr><td>Breed</td><td>Name</td><td>Age</td><td>Photo</td></tr>\n";
    for (const DogObject& dog : this->adoptionList) {
        fout << "<tr><td>" << dog.getBreed() << "</td>"
            << "<td>" << dog.getName() << "</td>"
            << "<td>" << std::to_string(dog.getAge()) << "</td>"
            << "<td><a href=\"" << dog.getPhoto() << "\">" << dog.getPhoto() << "</a></td>" << '\n';
    }
    fout << "</table></body></html>";
    fout.close();
}

string& HTMLRepo::getFilename()
{
    return this->userFilename;
}

HTMLRepo::~HTMLRepo() = default;
