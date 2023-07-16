#include "USERservice.h"
#include <algorithm>
#include "CSVrepository.h"
#include "HTMLrepository.h"

UserService::UserService(AdministratorRepository& _admin_repo, UserRepository* _user_repo) : admin_repo(_admin_repo)
{
	this->user_repo = _user_repo;
	repoTypeSelected = false;
}

UserService::UserService(AdministratorRepository& _admin_repo) : admin_repo(_admin_repo)
{
	repoTypeSelected = false;
}

vector<DogObject> UserService::getAllUserService()
{
	return this->user_repo->getAllUserRepo();
}

int UserService::getNumberElementsService()
{
	if (this->user_repo->getNumberElements() == 0) {
		string error;
		error += string("The adoption list is empty!");
		if (!error.empty())
			throw UserRepoException(error);
	}
	return this->user_repo->getNumberElements();
}

void UserService::addUserService(const DogObject& dog)
{
	this->user_repo->addUserRepo(dog);
	string dog_name = dog.getName();
	string dog_breed = dog.getBreed();
	int delete_index = this->admin_repo.findByName(dog_name);
	this->admin_repo.deleteAdminRepo(delete_index);
}

void UserService::repositoryType(const string& fileType)
{
	vector<DogObject> dog_list_user_mode;
	string userFile;
	if (fileType == "csv") {
	    userFile = R"(C:\Users\Andrei\source\repos\OOP9\OOP9\AdoptionList.csv)";
		if (!repoTypeSelected) {
			repoTypeSelected = true;
		}
		else {
			dog_list_user_mode = this->getAllUserService();
		}
		auto* repo = new CSVRepo(dog_list_user_mode, userFile);
		this->user_repo = repo;
		this->user_repo->writeToFile();
	}
	else if (fileType == "html") {
		userFile = R"(C:\Users\Andrei\source\repos\OOP9\OOP9\AdoptionList.html)";
		if (!repoTypeSelected) {
			repoTypeSelected = true;
		}
		else {
			dog_list_user_mode = this->getAllUserService();
		}
		auto* repo = new HTMLRepo(dog_list_user_mode, userFile);
		this->user_repo = repo;
		this->user_repo->writeToFile();
	}
	else {
		string error;
		error += string("The filename is invalid!");
		if (!error.empty())
			throw UserRepoException(error);
	}
}

string& UserService::getFileUserService()
{
	return this->user_repo->getFilename();
}

UserService::~UserService() = default;
