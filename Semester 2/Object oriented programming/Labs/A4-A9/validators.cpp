#include "validators.h"

ValidationException::ValidationException(string& _error_message)
{
	this->error_message = _error_message;
}

const char* ValidationException::what() const noexcept
{
	return error_message.c_str();
}

DogObjectValidator::DogObjectValidator() = default;

bool DogObjectValidator::validateString(const string& input_string)
{
	for (auto it : input_string)
		if (isdigit(it))
			return false;
	return true;
}

void DogObjectValidator::validateBreed(const string& breed)
{
	string errors;
	if (!validateString(breed))
		errors += string("The breed constains digits!");
	if (breed.size() == 0)
		errors += string("The breed is empty!");
	if (!errors.empty())
		throw ValidationException(errors);
}

void DogObjectValidator::validateName(const string& name)
{
	string errors;
	if (!validateString(name))
		errors += string("The name contains digits!");
	if (name.length() == 0)
		errors += string("The name is empty!");
	if (!isupper(name[0]))
		errors += string("The name should start with a capital letter!");
	if (!errors.empty())
		throw ValidationException(errors);
}

void DogObjectValidator::validateAgeString(const string& age)
{
	string errors;
	if (age.empty())
		errors += string("The age input is empty!");
	if (age.find_first_not_of("0123456789") != std::string::npos)
		errors += string("The age input has non-digit characters!");
	if (!errors.empty())
		throw ValidationException(errors);

}

void DogObjectValidator::validateAge(int age)
{
	string errors;
	if (age < 0)
		errors += string("Age can't be smaller than 0!");
	if (!errors.empty())
		throw ValidationException(errors);
}

void DogObjectValidator::validatePhoto(const string& photo)
{
	string errors;
	if (photo.length() == 0)
		errors += string("The link is empty!");
	if (photo.find("www") == string::npos && photo.find("com") == string::npos)
		errors += string("The link is not a valid!");
	if (!errors.empty())
		throw ValidationException(errors);
}

DogObjectValidator::~DogObjectValidator() = default;
