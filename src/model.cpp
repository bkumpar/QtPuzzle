/*
 * model.cpp
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */

#include <cmath>
#include <QDebug>
#include "model.h"

Model::Model(int rows, int cols) 
{
    m_grid = new DynamicArray<int>(rows, cols);
    initModel(rows, cols);
}

Model::~Model() 
{
    delete m_grid;
}

void Model::moveToEmptyPosition(Position p1 )
{
    if(insideGrid(p1))
    {
        Position p2 = m_emptyCellPosition;
        int tmp = (*m_grid)[p1.row()][p1.column()]	;
        (*m_grid)[p1.row()][p1.column()] =	(*m_grid)[p2.row()][p2.column()];
        (*m_grid)[p2.row()][p2.column()] = tmp	;
        m_emptyCellPosition.setPosition(p1);
    }
}


void Model::slide(Position tilePosition)
{
    if( isEmptyAt(tilePosition.lower()))
    {
        moveToEmptyPosition(tilePosition);
    }
    else if(isEmptyAt(tilePosition.upper()))
    {
        moveToEmptyPosition(tilePosition);
    }
    else if(isEmptyAt(tilePosition.left()))
    {
        moveToEmptyPosition(tilePosition);
    }
    else if(isEmptyAt(tilePosition.right()))
    {
        moveToEmptyPosition(tilePosition);
    }
    else
    {
        return;
    }

    emit changed();
    if (isSolved())
    {
        emit solved();
    }
    else
    {
        emit moved();
    }
}

void Model::slide(SlideDirection direction)
{

    switch (direction)
    {
    case sdUp:
        if(isTileAt(m_emptyCellPosition.lower()))
        {
            moveToEmptyPosition(m_emptyCellPosition.lower());
        }
        break;

    case sdDown:
        if(isTileAt(m_emptyCellPosition.upper()))
        {
            moveToEmptyPosition(m_emptyCellPosition.upper());
        }
        break;

    case sdRight:
        if(isTileAt(m_emptyCellPosition.left()))
        {
            moveToEmptyPosition(m_emptyCellPosition.left());
        }
        break;
    case sdLeft:
        if(isTileAt(m_emptyCellPosition.right()))
        {
            moveToEmptyPosition(m_emptyCellPosition.right());
        }
        break;
    }

    emit changed();

    if (isSolved())
    {
        emit solved();
    }
}

Position Model::randomPos()
{
    switch( rand() % 4 )
    {
    case 0:
        return m_emptyCellPosition.upper();
    case 1:
        return m_emptyCellPosition.lower();
    case 2:
        return m_emptyCellPosition.left();
    case 3:
        return m_emptyCellPosition.right();
    default:
        return m_emptyCellPosition;
    }
}

void Model::shuffle()
{
    for(int i = 0; i < SHUFFLE_STRENGHT; i++)
    {
        Position random = randomPos();
        moveToEmptyPosition(random);
    }
    emit changed();
}

Size &Model::size()
{
    return m_size;
}

bool Model::insideGrid(Position position)
{
    return  (0<=position.column()) &&
            (position.column()<m_size.columns()) &&
            (0<=position.row()) &&
            (position.row()<m_size.rows());

}

bool Model::isTileAt( Position tilePosition)
{
    return insideGrid(tilePosition) &&
            ((*m_grid)[tilePosition.row()][tilePosition.column()]) != emptyTileIndex;
}

bool Model::isEmptyAt( Position tilePosition)
{
    return insideGrid(tilePosition) &&
            (*m_grid)[tilePosition.row()][tilePosition.column()] == emptyTileIndex;
}

void Model::initModel(int rows, int columns)
{
    m_size.setSize(rows, columns);
    int tileNum = 0;
    for(int row = 0; row < m_size.rows(); row++)
        for(int column = 0; column < m_size.columns(); column++)
            (*m_grid)[row][column] = tileNum++;

    emptyTileIndex = tileNum - 1;
    setEmptyCellPosition(m_size.rows()-1, m_size.columns()-1);
}

void Model::initModel()
{
    initModel(m_size.rows(), m_size.columns());
}

void Model::setEmptyCellPosition(int row, int column)
{
    m_emptyCellPosition.setPosition(row, column);
    (*m_grid)[row][column] = emptyTileIndex;
}


bool Model::isSolved() 
{
    int tileNum = 0;
    for(int row = 0; row < m_size.rows(); row++)
        for(int column = 0; column < m_size.columns(); column++)
            if((*m_grid)[row][column] != tileNum++)
            {
                return false;
            }

    return true;
}

int Model::tileNum(int r, int c) 
{
    return (*m_grid)[r][c];
}

int Model::tilesCount()
{
    return m_size.rows()*m_size.columns()	;
}

