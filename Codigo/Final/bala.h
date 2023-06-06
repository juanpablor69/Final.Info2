#ifndef BALA_H
#define BALA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

#define tiempo 0.01

class Bala: public QGraphicsItem
{
    int posx, posy, ancho,largo,velocidad, vida;
public:
    Bala();
    Bala(int x,int y,int w,int h,int nivel);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);
    void MovRectilineo();

    double getPosx() const;
    double getPosy() const;
};

#endif // BALA_H
