/*
 * mainwindow.cpp
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */

#include "mainwindow.h"
#include <QStatusBar>
#include <QMessageBox>

#define DEFAULT_ROWS 3
#define DEFAULT_COLUMNS 4

MainWindow::MainWindow()
{
    this->setWindowIcon(QIcon(":main"));
    m_controller = new Controller();
    m_timer = new QTimer();
    m_timer->setInterval(1000);
    m_time = new QTime();
    this->setCentralWidget( m_controller->view());
    this->setFocusPolicy (Qt::StrongFocus );
    this->statusBar()->setSizeGripEnabled(true);
    this->resize(300,300);
    connect(m_controller, SIGNAL(solved()), this, SLOT(solved()));
    connect(m_controller, SIGNAL(moved(int)), this, SLOT(updateStatusBar()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateStatusBar()));
    this->statusBar()->showMessage(tr("Press F1 for help!"));
}

MainWindow::~MainWindow()
{
    delete m_controller;
    delete m_timer;
    delete m_time;
}



void MainWindow::showHelp()
{
    QMessageBox::information(this
                             , tr("Puzzle Help")
                             , tr("F1 - This help\n"
                                  "F2 - Start game\n"
                                  "F4 - Change picture\n"
                                  "F6 - About Qt\n\n"
                                  "Use arrows or mouse click to move puzzle\n")
                             ,QMessageBox::Ok );
    this->statusBar()->showMessage(tr(""));
}


void MainWindow::keyPressEvent ( QKeyEvent * event )
{
    switch (event->key())
    {
    case Qt::Key_F1:
        showHelp();
        break;
    case Qt::Key_F2:
        m_controller->shuffle();
        m_controller->newGame();
        m_time->start();
        m_timer->stop();
        m_timer->start();
        this->repaint();
        event->accept();
        break;
    case Qt::Key_F4:
        this->statusBar()->showMessage(tr(""));
        m_controller->changeImage();
        m_timer->stop();
        this->repaint();
        event->accept();
        break;
    case Qt::Key_F6:
        QMessageBox::aboutQt(this, tr("About Qt"));
        event->accept();
        break;

    default:
        event->ignore();
    }
}

void MainWindow::updateStatusBar()
{
    int movesCount = m_controller->moves();
    int elapsedTimeSec = m_time->elapsed()/1000;
    QString statusMsg = tr("Move: %1 Elapsed time: %2 sec").arg(movesCount).arg(elapsedTimeSec);
    this->statusBar()->showMessage(statusMsg);
    this->repaint();
}

void MainWindow::solved()
{

    m_timer->stop();
    int movesCount = m_controller->moves();
    int elapsedTimeSec = m_time->elapsed()/1000;

    QMessageBox::information(this
                             , tr("Congratulation")
                             , tr("You just solved puzzle in %1 moves and spent %2 seconds!").arg(movesCount).arg(elapsedTimeSec)
                             ,QMessageBox::Ok );

}


