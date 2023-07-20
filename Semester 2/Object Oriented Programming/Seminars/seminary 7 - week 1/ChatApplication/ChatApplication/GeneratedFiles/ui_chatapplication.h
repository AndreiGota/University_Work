/********************************************************************************
** Form generated from reading UI file 'chatapplication.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATAPPLICATION_H
#define UI_CHATAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatApplicationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatApplicationClass)
    {
        if (ChatApplicationClass->objectName().isEmpty())
            ChatApplicationClass->setObjectName(QStringLiteral("ChatApplicationClass"));
        ChatApplicationClass->resize(600, 400);
        menuBar = new QMenuBar(ChatApplicationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ChatApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatApplicationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChatApplicationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ChatApplicationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ChatApplicationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChatApplicationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatApplicationClass->setStatusBar(statusBar);

        retranslateUi(ChatApplicationClass);

        QMetaObject::connectSlotsByName(ChatApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatApplicationClass)
    {
        ChatApplicationClass->setWindowTitle(QApplication::translate("ChatApplicationClass", "ChatApplication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatApplicationClass: public Ui_ChatApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATAPPLICATION_H
