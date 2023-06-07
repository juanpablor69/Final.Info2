#include "bala.h"

Bala::Bala()
{

}

Bala::Bala(int x, int y, int w, int h,int nivel)
{
    this->posx=x;
    this->posy=y;
    this->ancho=w;
    this->largo=h;
    this->velocidad=(90*nivel)/2;
    setPos(posx,posy);
}

QRectF Bala::boundingRect() const
{
    return QRectF(2*posx,2*posy,2*ancho,2*largo);
}

void Bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap bala(":/images/bala(2).png");
    painter->drawPixmap(boundingRect(),bala,bala.rect());
}

void Bala::MovRectilineo()
{
    posx-=(velocidad*tiempo);
}

double Bala::getPosx() const
{
    return posx;
}

double Bala::getPosy() const
{
 return posy;
}
