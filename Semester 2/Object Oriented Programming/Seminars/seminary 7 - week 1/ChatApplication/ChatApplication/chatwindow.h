#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "ui_chatwindow.h"
#include "User.h"
#include "Message.h"
#include <vector>
#include "ChatSession.h"

class ChatWindow : public QWidget, public Observer
{
	Q_OBJECT

private:
	Ui::ChatWindow ui;
	User user;
	ChatSession& chatSession;

public:
	ChatWindow(const User& u, ChatSession& s, QWidget *parent = 0);
	~ChatWindow();

	// override the update method from the Observer class
	void update() override;

	void sendMessage();
};

#endif // CHATWINDOW_H
