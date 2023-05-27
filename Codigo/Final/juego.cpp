//Aqui vamos a manejar los diferentes modos o pantallas
#include "juego.h"

Juego::Juego()
{

}

void Juego::escena_Menu()
{
    menu = new QGraphicsScene ;
    menu->setSceneRect(0,0,736,414);
    menu->setBackgroundBrush(QImage(":/menu1/menu2.jpg"));
}

void Juego::nivel_1()
{
    mundo1 = new QGraphicsScene;
    mundo1->setSceneRect(0,0,736,414);
    mundo1->setBackgroundBrush(QImage(":/menu1/video_preview_0000.jpg").scaled(736,414));

    air=new Avion(15,15,30);
    mundo1->addItem(air);
}
