#include "chatwindow.h"
#include "MyTextEdit.h"

ChatWindow::ChatWindow(const User& u, ChatSession& s, QWidget *parent): QWidget(parent), user{ u }, chatSession{ s }
{
	ui.setupUi(this);
	this->ui.messageListWidget->setIconSize(QSize(70, 70));
	this->ui.messageListWidget->setWordWrap(true);
	this->setWindowTitle(QString::fromStdString(this->user.getName()));

	// register the observer
	this->chatSession.registerObserver(this);

	QObject::connect(this->ui.sendButton, &QPushButton::clicked, this, [&]() { this->sendMessage();	});

	QObject::connect(this->ui.messageTextEdit, &MyTextEdit::enterPressed, this, [&]() { this->sendMessage(); });
}

ChatWindow::~ChatWindow()
{
	this->chatSession.unregisterObserver(this);
}

void ChatWindow::update()
{
	this->ui.messageListWidget->clear();
	std::vector<std::pair<User, Message>> messages = this->chatSession.getMessages();
	for (auto& msg : messages)
	{
		QPixmap pixmap{ QString::fromStdString(msg.first.getUniqueUserName() + ".jpg") };
		QIcon icon{ pixmap };
		QListWidgetItem* item = new QListWidgetItem{icon, ""};
		item->setToolTip(QString::fromStdString(msg.second.getTimestampAsString()));

		if (msg.first == this->user)
		{
			item->setText(QString::fromStdString(msg.second.getMessageString()));
			item->setForeground(QBrush{ QColor{ Qt::darkMagenta } });
			item->setTextAlignment(Qt::AlignRight);
		}
		else
		{
			item->setText(QString::fromStdString("[" + msg.first.getName() + "]: " + msg.second.getMessageString()));
		}

		this->ui.messageListWidget->addItem(item);
	}
}

void ChatWindow::sendMessage()
{
	// get the message
	std::string m = this->ui.messageTextEdit->toPlainText().toStdString();
	Message msg{ m };

	// add the message to the chat session
	this->chatSession.addMessage(this->user, msg);

	// clear the text endit
	this->ui.messageTextEdit->clear();
}
