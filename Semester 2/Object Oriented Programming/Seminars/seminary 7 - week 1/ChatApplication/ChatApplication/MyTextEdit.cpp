#include "MyTextEdit.h"

MyTextEdit::MyTextEdit(QWidget *parent): QTextEdit{parent}
{

}

MyTextEdit::~MyTextEdit()
{

}

void MyTextEdit::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Return)
	{
		emit enterPressed();
	}
	else
	{
		QTextEdit::keyPressEvent(event);
	}
}
