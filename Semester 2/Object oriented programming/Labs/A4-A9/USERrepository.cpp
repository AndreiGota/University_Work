#include "USERrepository.h"


UserRepository::UserRepository(vector<DogObject>& adoption_list)
{
	this->adoptionList = adoption_list;
}

UserRepository::UserRepository() = default;

UserRepository::~UserRepository() = default;

UserRepoException::UserRepoException(string& _error_message)
{
	this->error_message = _error_message;
}

const char* UserRepoException::what() const noexcept
{
	return error_message.c_str();
}
