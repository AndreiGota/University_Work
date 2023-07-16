#pragma once
#include "domain.h"

class ValidationException : public exception {
private:
	string error_message;
public:
	explicit ValidationException(string& _error_message);
	const char* what() const noexcept override;
};

class DogObjectValidator {
public:
	DogObjectValidator();
	bool validateString(const string& input_string);
	void validateBreed(const string& breed);
	void validateName(const string& name);
	void validateAgeString(const string& age);
	void validateAge(int age);
	void validatePhoto(const string& photo);
	~DogObjectValidator();
};