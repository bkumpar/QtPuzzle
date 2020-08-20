/*
 * tile.cpp
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */
#include <QPainter>
#include "tile.h"

Tile::Tile(const QPixmap & pixmap)
	:QPixmap(pixmap),m_style3d(true)
{
	QPainter painter(this);
	QPen pen(Qt::lightGray,Qt::SolidPattern);
			
	painter.setPen(pen);
	painter.drawLine(0,size().height()-1,0,0);
	painter.drawLine(0,0,size().width()-1,0);
	
	pen.setColor(Qt::darkGray);
	painter.setPen(pen);
	painter.drawLine(size().width()-1,0,size().width()-1,size().height()-1);
	painter.drawLine(size().width()-1,size().height()-1,0,size().height()-1);
}

Tile::Tile()
{

}

Tile::~Tile()
{

}

bool Tile::style3d()
{
	return m_style3d;
}

void Tile::setStyle3d(bool value)
{
	m_style3d = value;
}

