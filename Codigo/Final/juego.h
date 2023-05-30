#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QList>

#include <avion.h>
#include <misil.h>
#include <limites.h>

class Juego: public QObject, public QGraphicsPixmapItem
{
public:
    int posXAv,posYAv;
    Juego();
    QGraphicsScene *menu, *mundo1;
    Avion *air;
    Misil *misil1;
    QList<Limites*>limite;

    void escena_Menu(); //Funcion para configurar el menu
    void Funlimites();
    void nivel_1();
    void act_misil(int,int);
    bool ColAv_lim();
    bool ColMil_lim();
};

#endif // JUEGO_H
