/*
 * picture.cpp
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */

#include "picture.h"
#include <QDebug>
#include <QString>

Picture::Picture() 
{
     m_currentImageIndex = 1;
}

Picture::Picture(int width, int height) : QPixmap(width, height)
{
    m_currentImageIndex = 1;
}

Picture::~Picture() 
{

}

void Picture::loadNext()
{
    load(++m_currentImageIndex % IMAGES_COUNT);
}

void Picture::load(int index)
{
// 	example how to call function from base class:
	QPixmap::load(QString(":image_%1").arg(index));
}
