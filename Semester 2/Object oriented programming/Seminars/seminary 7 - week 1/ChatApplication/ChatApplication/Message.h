#pragma once
#include <ctime>
#include <string>
#include <sstream>

class Message
{
private:
	tm timestamp;
	std::string message;

public:
	Message(const std::string& msg) : message{ msg }
	{
		// get the current date and time
		time_t now = time(0);
		tm *ltm = localtime(&now);
		this->timestamp = *ltm;
	}

	std::string getMessageString() const { return this->message; }
	tm getTimestamp() const { return this->timestamp; }

	std::string getTimestampAsString()
	{
		std::stringstream t;
		t << "[" << this->timestamp.tm_mday << "." << this->timestamp.tm_mon + 1 << "." << this->timestamp.tm_year + 1900;
		t << "; " << this->timestamp.tm_hour << ":" << this->timestamp.tm_min << "]";
		return t.str();
	}
};