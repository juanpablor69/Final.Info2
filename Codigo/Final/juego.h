#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QList>
#include <map>
#include <QCoreApplication>
#include <QMap>

#include <avion.h>
#include <misil.h>
#include <limites.h>
#include <bolafuego.h>

class Juego: public QObject, public QGraphicsPixmapItem
{
public:
    Juego();
    QGraphicsScene *menu, *mundo1, *mundo2;
    Avion *air;
    Misil *misil1;
    Bolafuego *BFuego;
    QList<Limites*>limite;
    QMap<int, Bolafuego*> bolasf;
//    QList<Bolafuego*>bolasf;
//    map<*misil1,int>;

    int posXAv,posYAv;
    int nivel=0,puntaje=0;

    void escena_Menu(); //Funcion para configurar el menu
    void Funlimites();
    void nivel_1();
    void nivel_2();
    void act_misil(int,int);
    void act_bfuego(int,int,int);
    bool ColAv_lim(); //COLISION AVION CONTRA LIMITES DEL JUEGO
//    bool ColAv_BolasF(int,int nivel);
    bool ColAv_BolasF(int);
    void manejoColisione();
//    void Act_MovFuego();
//    bool ColMil_lim();
//    void mostrar();

public slots:
    void Act_MovFuego();

};

#endif // JUEGO_H
