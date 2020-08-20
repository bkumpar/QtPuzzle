/*
 * position.h
 *
 *  Created on: 30.12.2011.
 *      Author: Boris Kumpar
 */

#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
    Position();
    Position(int row, int column);

    void setPosition(int row, int column);
    void setPosition(Position  pos);
    int row();
    int column();
    Position upper();
    Position lower();
    Position right();
    Position left();

private:
    int m_row;
    int m_column;

};

#endif
