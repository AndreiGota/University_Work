#include "ADMINrepository.h"
#include <algorithm>
#include <fstream>

void AdministratorRepository::loadDogsFromFile()
{
	if (!this->dogsFilename.empty()) {
		DogObject dogFromFile;
		ifstream fin(this->dogsFilename);
		while (fin >> dogFromFile) {
			if (find(this->admin_repo_dog_list.begin(), this->admin_repo_dog_list.end(), dogFromFile) == this->admin_repo_dog_list.end())
				this->admin_repo_dog_list.push_back(dogFromFile);
		}
		fin.close();
	}
}

void AdministratorRepository::writeDogsToFile()
{
	if (!this->dogsFilename.empty()) {
		ofstream fout(this->dogsFilename);
		for (const DogObject& dog : this->admin_repo_dog_list)
			fout << dog << endl;
		fout.close();
	}
}

AdministratorRepository::AdministratorRepository(vector<DogObject>& repo_array, string& dogs_filename)
{
	this->admin_repo_dog_list = repo_array;
	this->dogsFilename = dogs_filename;
}

void AdministratorRepository::initialiseAdminRepo()
{
	this->loadDogsFromFile();
}

vector<DogObject>& AdministratorRepository::getAllAdminRepo()
{
	if (this->admin_repo_dog_list.empty()) {
		string error;
		error += string("The database is empty!");
		if (!error.empty())
			throw AdminRepoException(error);
	}
	return this->admin_repo_dog_list;
}

int AdministratorRepository::getNumberElements()
{
	if (this->admin_repo_dog_list.empty()) {
		string error;
		error += string("The database is empty!");
		if (!error.empty())
			throw AdminRepoException(error);
	}
	return this->admin_repo_dog_list.size();
}

void AdministratorRepository::addAdminRepo(const DogObject& dog)
{
	int existing = this->findByName(dog.getName());
	if (existing != -1) {
		string error;
		error += string("The dog already exists!");
		if (!error.empty())
			throw AdminRepoException(error);
	}
	this->admin_repo_dog_list.push_back(dog);
	this->writeDogsToFile();
}

void AdministratorRepository::deleteAdminRepo(int delete_index)
{
	if (delete_index == -1) {
		string error;
		error += string("The dog does not exist!");
		if (!error.empty())
			throw AdminRepoException(error);
	}
	this->admin_repo_dog_list.erase(this->admin_repo_dog_list.begin() + delete_index);
	this->writeDogsToFile();
}

void AdministratorRepository::updateAdminRepo(int update_index, const DogObject& new_dog)
{
	if (update_index == -1) {
		string error;
		error += string("The dog does not exist!");
		if (!error.empty())
			throw AdminRepoException(error);
	}
	this->admin_repo_dog_list[update_index] = new_dog;
	this->writeDogsToFile();
}

int AdministratorRepository::findByName(const string& name)
{
	int searched_index = -1;
	vector<DogObject>::iterator it;
	it = find_if(this->admin_repo_dog_list.begin(), this->admin_repo_dog_list.end(), [&name](DogObject& dog)
		{
			return dog.getName() == name;
		});
	if (it != this->admin_repo_dog_list.end())
		searched_index = it - this->admin_repo_dog_list.begin();
	return searched_index;
}



AdministratorRepository::~AdministratorRepository() = default;

AdminRepoException::AdminRepoException(string _error_message)
{
	this->error_message = _error_message;
}

const char* AdminRepoException::what() const noexcept
{
	return error_message.c_str();
}
