/*
 * model.h
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */

#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "size.h"
#include "position.h"
#include "dynamicarray.h"

#define SHUFFLE_STRENGHT 100

enum SlideDirection 
{
    sdUp,
    sdDown,
    sdLeft,
    sdRight
};

class Model : public QObject {
    Q_OBJECT
public:
    Model(int rows, int cols);
    ~Model();

    Size & size();
    int tileNum(int r, int c) ;
    int tilesCount();
    void initModel(int rows, int columns);
    void initModel();
    int emptyTileIndex;

public slots:
    void slide(Position tilePosition);
    void slide(SlideDirection direction);
    void shuffle();

signals:
    void changed();
    void moved();
    void solved();

private:
    int m_value;
    Size  m_size;
    Position m_emptyCellPosition;
    DynamicArray<int> * m_grid;
    bool isTileAt( Position tilePosition);
    bool isEmptyAt( Position tilePosition);
    bool insideGrid( Position position);
    bool isSolved();
    void moveToEmptyPosition( Position p1);
    Position randomPos();

    void setEmptyCellPosition(int row, int column);
};

#endif /* MODEL_H_ */
