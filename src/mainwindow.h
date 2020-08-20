
/*
 * mainwindow.h
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */
 
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QTime>
#include <QMainWindow>
#include <QPaintEvent>
#include <QDebug>

#include "model.h"
#include "view.h"
#include "controller.h"
#include "picture.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
	public:
		MainWindow();
		~MainWindow();

    public slots:
        void updateStatusBar();
        void solved();

	protected:
		void keyPressEvent ( QKeyEvent * event );

	private:
        Controller * m_controller;
        QTimer * m_timer;
        QTime * m_time;
        void showHelp();
};

// set VCINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC
#endif

