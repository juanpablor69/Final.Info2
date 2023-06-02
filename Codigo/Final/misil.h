#ifndef MISIL_H
#define MISIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>

#define tiempo 0.01

class Misil: public QGraphicsItem
{
    double posx, posy, radio,velx,vely,velocidad,angulo;
public:
    Misil();
    Misil(double x,double y,double r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void CalcularVelocidad();
    void CalcularPosicion();
    void ActualizarVelocidad();


    double getPosx() const;
    double getPosy() const;
};

#endif // MISIL_H
