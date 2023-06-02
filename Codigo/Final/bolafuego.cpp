#include "bolafuego.h"

Bolafuego::Bolafuego()
{

}

Bolafuego::Bolafuego(double x,double y, double r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->angulo=0;
    this->velocidad=30;
    setPos(posx,posy);
}

QRectF Bolafuego::boundingRect() const
{
    return QRectF(2*posx,2*posy,2*radio,2*radio);
}

void Bolafuego::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap bfuego(":/images/fuego.png");
    painter->drawPixmap(boundingRect(),bfuego,bfuego.rect());
}

void Bolafuego::MovRectilineo()
{
    posx-=(velocidad*tiempo);
}

double Bolafuego::getPosx() const
{
    return posx;
}

double Bolafuego::getPosy() const
{
    return posy;
}
