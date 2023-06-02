#ifndef BOLAFUEGO_H
#define BOLAFUEGO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>

#define tiempo 0.01

class Bolafuego: public QGraphicsItem
{
    double posx, posy, radio,velx,vely,velocidad,angulo;
public:
    Bolafuego();
    Bolafuego(double x,double y,double r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void MovRectilineo();

    double getPosx() const;
    double getPosy() const;
};

#endif // BOLAFUEGO_H
