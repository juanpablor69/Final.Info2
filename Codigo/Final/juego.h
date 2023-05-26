#ifndef JUEGO_H
#define JUEGO_H

#include <QObject>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Juego: public QObject, public QGraphicsPixmapItem
{
public:
    Juego();
    QGraphicsScene *menu, *mundo1;
    void escena_Menu(); //Funcion para configurar el menu
    void nivel_1();
};

#endif // JUEGO_H
