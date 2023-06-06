#include "bolafuego.h"

Bolafuego::Bolafuego()
{

}

Bolafuego::Bolafuego(double x,double y, double w,double h,int nivel,int n)
{
    this->posx=x;
    this->posy=y;
    this->ancho=w;
    this->largo=h;
    this->velocidad=(90*nivel)/2;
    this->nbolas=n;
    setPos(posx,posy);
}

QRectF Bolafuego::boundingRect() const
{
    return QRectF(2*posx,2*posy,2*ancho,2*largo);
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
