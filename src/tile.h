/*
 * tile.h
 *
 *  Created on: 22.12.2011.
 *      Author: Boris Kumpar
 */

#ifndef TILE_H
#define TILE_H

#include <QPixmap>

class Tile : public QPixmap {
	public:
		Tile();
		Tile(const QPixmap & pixmap);
		virtual ~Tile();
		
		bool style3d();
		void setStyle3d(bool value);
		
	private:
		bool m_style3d;
	
};

#endif /* TILE_H */
