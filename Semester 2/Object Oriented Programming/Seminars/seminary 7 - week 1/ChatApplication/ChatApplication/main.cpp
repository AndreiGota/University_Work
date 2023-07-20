#include "chatapplication.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include "ChatSession.h"
#include "chatwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	ChatSession session;

	ChatWindow user1{ User{ "jon.snow", "Jon Snow" }, session };
	ChatWindow user2{ User{ "tyrion.lannister", "Tyrion Lannister" }, session };
	ChatWindow user3{ User{ "arya.stark", "Arya Stark" }, session };
	ChatWindow user4{ User{ "daenerys.targaryen", "Daenerys Targaryen" }, session };
	user1.show();
	user2.show();
	user3.show();
	user4.show();

	// move the windows across the screen
	// get the screen's coordinates
	QRect screenRect = QApplication::desktop()->screen()->rect();
	int x = screenRect.x();
	int y = screenRect.y();
	int width = screenRect.width();
	int height = screenRect.height();

	// move the first window in the top left corner
	user1.move(x, y);
	// move the second lower
	user2.move(x + user1.rect().width(), y + height - user2.rect().height() - 100);
	// move the third in the top right corner
	user3.move(x + width - user3.rect().width(), y);
	// move the fourth lower
	user4.move(x + width - 2 * user4.rect().width(), y + height - user4.rect().height() - 100);

	return a.exec();
}
