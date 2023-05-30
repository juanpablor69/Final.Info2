#ifndef LIMITES_H
#define LIMITES_H

#include <QGraphicsItem>
#include <QPainter>

class Limites: public QGraphicsItem
{
    int posx, posy,w,h;
public:
    Limites();
    Limites(int x, int y, int w, int h);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);

};

#endif // LIMITES_H
