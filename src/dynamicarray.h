/*
* dynamicarray.h 

* declaration and definition in one file required for templates!!!
*
* Created: 25.12.2011.
* Author: Boris Kumpar
*/

#ifndef  DYNAMICARRAY_H
#define  DYNAMICARRAY_H
#include <QVector>

template <typename T>
class DynamicArray 
{
public:
    DynamicArray();

    DynamicArray(int rows, int cols);

    QVector<T> & operator[](int i) ;
	
    const QVector<T> & operator[] (int i) const;
	
    void resize(int rows, int cols);
	
private:
    QVector<QVector<T> > m_array;
};


template <typename T> 
DynamicArray<T>::DynamicArray(){}

template <typename T> 
DynamicArray<T>::DynamicArray(int rows, int cols): m_array(rows, QVector<T>(cols)){}

template <typename T>
QVector<T> & DynamicArray<T>::operator[](int i) 
{ 
	return m_array[i];
}
	
template <typename T>
const QVector<T> & DynamicArray<T>::operator[] (int i) const 
{ 
	return m_array[i];
}
	
template <typename T>
void DynamicArray<T>::resize(int rows, int cols)//resize the two dimentional array .
{
	m_array.resize(rows);
	for(int i = 0;i < rows;++i) 
	{
		m_array[i].resize(cols);
	}
}



#endif

