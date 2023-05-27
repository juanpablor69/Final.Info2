#include "avion.h"

Avion::Avion()
{

}

Avion::Avion(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=3;
    setPos(posx,posy);
}

QRectF Avion::boundingRect() const
{
    return QRectF(2*posx,2*posy,2*radio,2*radio);
}

void Avion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap avion(":/menu1/pngwing.com (1).png");
    painter->drawPixmap(boundingRect(),avion,avion.rect());
}

void Avion::MovArriba()
{
    posy-=velocidad;
    setPos(posx, posy);
}

void Avion::MovAbajo()
{
    posy+=velocidad;
    setPos(posx, posy);
}








