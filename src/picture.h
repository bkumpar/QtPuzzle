/*
 * picture.h
 *
 *  Created on: 21.12.2011.
 *      Author: Boris
 */

#ifndef PICTURE_H
#define PICTURE_H
#include <QPixmap>
#define IMAGES_COUNT 4

class Picture : public QPixmap {
public:
	Picture();
	Picture(int width, int height);
	virtual ~Picture();
    void loadNext();
	void load(int index);
private:
    int m_currentImageIndex;
};

#endif /* PICTURE_H */
