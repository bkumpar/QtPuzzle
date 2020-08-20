/*
 * size.h
 *
 *  Created on: 30.12.2011.
 *      Author: Boris Kumpar
 */

#ifndef SIZE_H
#define SIZE_H


class Size
{
public:
    Size();
    Size(int rows, int columns);
    void setSize(int rows, int columns);
    void setSize(Size & size);
    int rows();
    int columns();

private:
    int m_rows;
    int m_columns;

};



#endif
