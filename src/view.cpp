/*
 * view.cpp
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */

#include <QPainter>
#include <QRect>
#include <QPoint>
#include "view.h"

View::View(Model * model)
{
    m_model = model;
    m_picture = new Picture();
    m_buffer = NULL;
    m_currentImageIndex = 1;
    this->loadPicture(m_currentImageIndex);
    this->setFocusPolicy (Qt::StrongFocus);
    makeConnections();
}


View::~View() 
{
    if(m_buffer)
    {
        delete m_buffer;
    }
    delete m_picture;
}


void View::loadPicture(int pictureIndex)
{
    m_picture = new Picture();
    m_picture->load(pictureIndex);
    int w = m_picture->width();
    int h = m_picture->height();
    if(m_buffer)
    {
        delete m_buffer;
    }
    m_buffer = new Picture(w,h);
    m_tileList.resize(m_model->tilesCount()) ;
    calcTileSize();
    m_model->initModel();
    this->redrawBuffer();
}


void View::changePicture()
{
    this->loadPicture(++m_currentImageIndex % IMAGES_COUNT);
}

Picture * View::picture()
{
    return m_picture;
}

void View::redrawBuffer()
{
    QPainter painter(m_buffer);

    for(int i=0; i<m_model->size().rows(); i++)
        for(int j=0; j<m_model->size().columns(); j++)
        {
            QPoint point(j*m_tileSize.width(), i*m_tileSize.height());
            int tileNum=m_model->tileNum(i,j);
            if( tileNum!=m_model->emptyTileIndex )
            {
                Tile tile = m_tileList[tileNum];
                painter.drawPixmap(point, tile);
            }
            else
            {
                QRect rect(point.x(), point.y() ,m_tileSize.width(), m_tileSize.height());
                painter.fillRect(rect, QBrush(QColor(Qt::gray),Qt::SolidPattern));
            }
        }
}

void View::update()
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(), *m_buffer);
}

void View::createTiles()
{
    int tileNum = 0;

    for(int i=0; i<m_model->size().rows(); i++)
        for(int j=0; j<m_model->size().columns(); j++)
        {
            int top = i*m_tileSize.height();
            int left= j*m_tileSize.width();
            int height=m_tileSize.height();
            int width= m_tileSize.width();

            QPixmap pixmap = m_picture->copy(QRect (left, top, width, height));
            Tile tile(pixmap);
            m_tileList[tileNum] = tile;
            ++tileNum;
        }

}

void View::deleteTiles()
{

    for(int i=0; i<m_tileList.size(); i++)
    {
        Tile tile = m_tileList[i];
        delete &tile;
    }

}

void View::calcTileSize()
{
    if ((m_picture!=NULL) && (m_model!=NULL))
    {
        m_tileSize.setHeight(m_picture->height()/3/*m_model->size().rows()*/);
        m_tileSize.setWidth(m_picture->width()/3/*m_model->size().columns()*/);
    }
}

void View::paintEvent ( QPaintEvent * /*event*/ )
{
    update();
}

void View::mousePressEvent ( QMouseEvent * event )
{
    if (event->button() == Qt::LeftButton)
    {
        m_model->slide(tilePos(event->pos()));
        event->accept();
        return;
    }
    event->ignore();
    return;

}
void View::keyPressEvent ( QKeyEvent * event )
{
    switch (event->key() )
    {
    case Qt::Key_Up:
        m_model->slide(sdUp);
        event->accept();
        break;
    case Qt::Key_Down:
        m_model->slide(sdDown);
        event->accept();
        break;
    case Qt::Key_Left:
        m_model->slide(sdLeft);
        event->accept();
        break;
    case Qt::Key_Right:
        m_model->slide(sdRight);
        event->accept();
        break;
    default:
        event->ignore();
    }
}

Position View::tilePos(const QPoint & pt)
{
    Position pos(pt.y()/m_tileSize.height(),pt.x()/m_tileSize.width() );
    return pos;
}

void View::modelChanged()
{
    this->redrawBuffer();
    this->repaint();
}

void View::makeConnections()
{
    connect(m_model, SIGNAL(changed()), this, SLOT(modelChanged()));
}
