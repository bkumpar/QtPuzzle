/*
 * size.cpp
 *
 *  Created on: 30.12.2011.
 *      Author: Boris Kumpar
 */

#include "size.h"

Size::Size()
{

}

Size::Size(int rows, int columns) :
    m_rows(rows),m_columns(columns)
{

}

void Size::setSize(int rows, int columns)
{
    m_rows = rows;
    m_columns = columns;
}

void Size::setSize(Size & size)
{
    m_rows =  size.rows();
    m_columns = size.columns();
}

int Size::rows()
{
    return m_rows;
}

int Size::columns()
{
    return m_columns;
}
