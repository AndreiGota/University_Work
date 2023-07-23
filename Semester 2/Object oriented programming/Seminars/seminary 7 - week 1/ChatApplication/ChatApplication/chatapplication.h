#ifndef CHATAPPLICATION_H
#define CHATAPPLICATION_H

#include <QtWidgets/QMainWindow>
#include "ui_chatapplication.h"

class ChatApplication : public QMainWindow
{
	Q_OBJECT

public:
	ChatApplication(QWidget *parent = 0);
	~ChatApplication();

private:
	Ui::ChatApplicationClass ui;
};

#endif // CHATAPPLICATION_H
