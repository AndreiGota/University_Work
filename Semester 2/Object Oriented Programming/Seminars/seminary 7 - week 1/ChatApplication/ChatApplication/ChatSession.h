#pragma once
#include "Observer.h"
#include "Message.h"
#include "User.h"
#include <map>

// this class only inherits from the Subject, it is the observable object
class ChatSession : public Subject 
{
private:
	std::vector<std::pair<User, Message>> messages;

public:
	void addMessage(const User& u, const Message& msg)
	{
		this->messages.push_back(std::pair<User, Message>(u, msg));
		this->notify();
	}

	std::vector<std::pair<User, Message>> getMessages() const { return this->messages; }
};