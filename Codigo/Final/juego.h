#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QList>
#include <map>

#include <avion.h>
#include <misil.h>
#include <limites.h>
#include <bolafuego.h>

class Juego: public QObject, public QGraphicsPixmapItem
{
public:
    Juego();
    QGraphicsScene *menu, *mundo1;
    Avion *air;
    Misil *misil1;
    Bolafuego *BFuego;
    QList<Limites*>limite;
//    map < *misil1 , int >;

    int posXAv,posYAv;
    int nivel=0;

    void escena_Menu(); //Funcion para configurar el menu
    void Funlimites();
    void nivel_1();
    void act_misil(int,int);
    void act_bfuego(int,int);
    bool ColAv_lim(); //COLISION AVION CONTRA LIMITES DEL JUEGO

//    bool ColMil_lim();
//    void mostrar();
};

#endif // JUEGO_H
