#ifndef IMAGENES_H
#define IMAGENES_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

#define PATH_BACKGROUND ":/imagenes/Menu/menu_back.jpg"

class Imagenes: public QGraphicsItem
{
    int posx,posy,h,an,image;
public:
    Imagenes();
    Imagenes(int,int,int,int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // IMAGENES_H
