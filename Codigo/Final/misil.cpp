#include "misil.h"

Misil::Misil()
{

}

Misil::Misil(double x, double y, double r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->angulo=0;
    this->velocidad=30;
    setPos(posx,posy);
}

double Misil::getPosx() const
{
    return posx;
}

double Misil::getPosy() const
{
    return posy;
}

QRectF Misil::boundingRect() const
{
    return QRectF(2*posx,2*posy,2*radio,2*radio);
}

void Misil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap misil(":/images/pngegg (1).png");
    painter->drawPixmap(boundingRect(),misil,misil.rect());
}

void Misil::CalcularVelocidad()
{
    velx= velocidad*cos(angulo);
    vely=velocidad*sin(angulo)-9.8*tiempo;
}

void Misil::CalcularPosicion()
{
    posx+=velx*tiempo;
    posy+=-(vely*tiempo-0.5*9.8*pow(tiempo,2));
}

void Misil::ActualizarVelocidad()
{
    velocidad=sqrt(pow(velx,2)+pow(vely,2));
    angulo=atan2(vely,velx);
}


