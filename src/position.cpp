/*
 * position.cpp
 *
 *  Created on: 30.12.2011.
 *      Author: Boris Kumpar
 */

#include "position.h"

Position::Position()
{

}

Position::Position(int row, int column)
    : m_row(row),m_column(column)
{

}

void Position::setPosition(int row, int column)
{
    m_row = row;
    m_column = column;
}

void Position::setPosition(Position  pos)
{
    m_row = pos.row();
    m_column = pos.column();
}

int Position::row()
{
    return m_row;
}

int Position::column()
{
    return m_column;
}

Position Position::upper()
{
    return Position(m_row-1, m_column);
}

Position Position::lower()
{
    return Position(m_row+1, m_column);
}

Position Position::right()
{
    return Position(m_row, m_column+1);
}

Position Position::left()
{
    return Position(m_row, m_column-1);
}

