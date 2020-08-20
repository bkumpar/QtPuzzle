/*
 * view.h
 *
 *  Created on: 21.12.2011.
 *      Author: Boris Kumpar
 */

#ifndef VIEW_H_
#define VIEW_H_

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QVector>

#include "position.h"
#include "model.h"
#include "tile.h"
#include "picture.h"

class View : public QWidget
{
	Q_OBJECT
	public:
        View(Model *model);
		virtual ~View();

        Picture * picture();
        void createTiles();
		void redrawBuffer();
        void update();
        void loadPicture(int pictureIndex);
        void changePicture();

	public slots:
        void modelChanged();
		
	protected:
		void paintEvent ( QPaintEvent * /*event*/ );
		void mousePressEvent ( QMouseEvent * event );
        void keyPressEvent ( QKeyEvent * event );

	private:
		Picture * m_buffer;
		Picture * m_picture;
		Model * m_model;
        QVector<Tile> m_tileList;
		QSize m_tileSize;
		
		void calcTileSize();
		void deleteTiles();
        void drawTile(Position * position);
		void initClass();
		void makeConnections();
        Position tilePos(const QPoint & pt);
        int m_currentImageIndex;
};

#endif /* VIEW_H_ */
