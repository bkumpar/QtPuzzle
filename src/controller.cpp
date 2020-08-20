#include "controller.h"

#define DEFAULT_ROWS 3
#define DEFAULT_COLUMNS 3

Controller::Controller(QObject *parent) : QObject(parent)
{
    m_movesCounter = 0;
    m_model = new Model(DEFAULT_ROWS, DEFAULT_COLUMNS);
    m_view = new View(m_model);
    m_view->createTiles();
    m_view->redrawBuffer();
    connect(m_model, SIGNAL(moved()), this, SLOT(onMoved()));
    connect(m_model, SIGNAL(solved()), this, SIGNAL(solved()));

}

Controller::~Controller()
{
    delete m_view;
    delete m_model;
}

View * Controller::view()
{
    return  m_view;
}

void Controller::shuffle()
{
    m_model->shuffle();
    m_view->redrawBuffer();
}

void Controller::newGame()
{
    m_view->createTiles();
    m_view->redrawBuffer();
    m_movesCounter = 0;
}

void Controller::changeImage()
{
    m_view->changePicture();
    m_view->createTiles();
    m_model->initModel();
    m_view->redrawBuffer();
}

void Controller::onMoved()
{
    m_movesCounter++;
    emit moved(m_movesCounter);
}

int Controller::moves()
{
    return m_movesCounter;
}
