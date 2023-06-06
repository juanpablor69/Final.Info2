#ifndef AVION_H
#define AVION_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class Avion: public QGraphicsItem
{
    int posx, posy, ancho,largo,velocidad, vida;
public:
    Avion();
    Avion(int x,int y,int w,int h);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void MovArriba();
    void MovAbajo();
    void MovDerecha();

    double getPosx() const;
    double getPosy() const;
};

#endif // AVION_H
