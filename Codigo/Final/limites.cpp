#include "limites.h"

Limites::Limites()
{

}

Limites::Limites(int x, int y, int w, int h)
{
    this->posx=x;
    this->posy=y;
    this->w=w;
    this->h=h;
    setPos(posx,posy);
}

QRectF Limites::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void Limites::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}
