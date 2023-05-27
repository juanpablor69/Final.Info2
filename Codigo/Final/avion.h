#ifndef AVION_H
#define AVION_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class Avion: public QGraphicsItem
{
    int posx, posy, radio,velocidad, vida;
public:
    Avion();
    Avion(int x,int y,int r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void MovArriba();
    void MovAbajo();
};

#endif // AVION_H
