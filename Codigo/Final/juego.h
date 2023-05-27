#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include <avion.h>

class Juego: public QObject, public QGraphicsPixmapItem
{
public:
    Juego();
    QGraphicsScene *menu, *mundo1;
    Avion *air;
    void escena_Menu(); //Funcion para configurar el menu
    void nivel_1();
//    void keyPressEvent(QKeyEvent *evento);
};

#endif // JUEGO_H
