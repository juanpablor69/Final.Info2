#include "avion.h"

Avion::Avion()
{

}

Avion::Avion(int x, int y, int w,int h)
{
    this->posx=x;
    this->posy=y;
    this->ancho=w;
    this->largo=h;
    this->velocidad=3;
    setPos(posx,posy);
}

double Avion::getPosx() const
{
    return posx;
}

double Avion::getPosy() const
{
    return posy;
}

QRectF Avion::boundingRect() const
{
    return QRectF(2*posx,2*posy,2*ancho,2*largo);
}

void Avion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap avion(":/images/avion.png");
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

void Avion::MovDerecha()
{
    posx+=velocidad;
    setPos(posx,posy);
}








