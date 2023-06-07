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
#include <bala.h>

class Juego: public QObject, public QGraphicsPixmapItem
{
public:
    Juego();
    QGraphicsScene *menu, *mundo1, *mundo2;
    Avion *air;
    Misil *misil1;
    Bolafuego *BFuego;
    Bala *balas;
    QList<Limites*>limite;
    QMap<int, Bolafuego*> bolasf;
    QMap<int, Bala*> balasmap;
//    QList<Bolafuego*>bolasf;
//    map<*misil1,int>;

    int posXAv,posYAv;
//    int nivel=0;
//    int puntaje=0;

    void escena_Menu(); //Funcion para configurar el menu
    void Funlimites(int nivel);
    void nivel_1(int nivel);
    void nivel_2(int nivel);
    void act_misil(int,int);
    void act_bfuego(int,int,int);
    void act_bala(int y,int nbalas,int nivel);

    bool ColAv_lim(); //COLISION AVION CONTRA LIMITES DEL JUEGO
    bool ColAv_BolasF(int nbolas,int nivel);
    bool ColAv_Bala(int nbalas,int nivel);
//    bool ColAv_BolasF(int,int nivel);
//    void Act_MovFuego();
//    bool ColMil_lim();
//    void mostrar();

public slots:
    void Act_MovFuego();

};

#endif // JUEGO_H
