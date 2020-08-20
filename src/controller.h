#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"
#include "view.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    View * view();
    int moves();

signals:
    void moved(int);
    void solved();

public slots:
    void shuffle();
    void newGame();
    void changeImage();
    void onMoved();

private:
    View * m_view;
    Model * m_model;
    int m_movesCounter;

};

#endif // CONTROLLER_H
