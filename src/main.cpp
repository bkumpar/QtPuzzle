/*
 * main.cpp
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */

#include <QApplication>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow * mainWindow = new MainWindow();
    mainWindow->show();
	return app.exec();
}


