#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include <avion.h>
#include <misil.h>

class Juego: public QObject, public QGraphicsPixmapItem
{
public:
    int posXAv,posYAv;
    Juego();
    QGraphicsScene *menu, *mundo1;
    Avion *air;
    Misil *misil1;
    void escena_Menu(); //Funcion para configurar el menu
    void nivel_1();
    void act_misil(int,int);
};

#endif // JUEGO_H
