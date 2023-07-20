#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>

class MyTextEdit : public QTextEdit
{
	Q_OBJECT

public:
	MyTextEdit(QWidget *parent);
	~MyTextEdit();

	// to handle the Enter event for the TextEdit
	void keyPressEvent(QKeyEvent *event);

signals:
	void enterPressed();
};

#endif // MYTEXTEDIT_H
