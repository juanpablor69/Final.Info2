//Aqui vamos a manejar los diferentes modos o pantallas
#include "juego.h"

Juego::Juego()
{

}

void Juego::escena_Menu()
{
    menu = new QGraphicsScene ;
    menu->setSceneRect(0,0,736,414);
    menu->setBackgroundBrush(QImage(":/images/menu2.jpg"));
}

void Juego::Funlimites()
{
    limite.push_back(new Limites(0,0,736,5));
    mundo1->addItem(limite.back());
    limite.push_back(new Limites(0,0,5,414));
    mundo1->addItem(limite.back());
    limite.push_back(new Limites(368,0,5,414));
    mundo1->addItem(limite.back());
    limite.push_back(new Limites(0,207,736,5));
    mundo1->addItem(limite.back());
}


void Juego::nivel_1()
{
    mundo1 = new QGraphicsScene;
    mundo1->setSceneRect(0,0,736,414);
    mundo1->setBackgroundBrush(QImage(":/images/video_preview_0000.jpg").scaled(736,414));

    air=new Avion(15,15,40);
    mundo1->addItem(air);

}

void Juego::act_misil(int x, int y) // ACTIVAR MISIL
{
    misil1=new Misil(x,y,15);
    mundo1->addItem(misil1);
}

void Juego::act_bfuego(int y,int nivel)
{
    BFuego=new Bolafuego(240,y,15,nivel);
    mundo1->addItem(BFuego);
}

bool Juego::ColAv_lim() //COLISION AVION CONTRA LIMITES DEL JUEGO
{
    QList<Limites*>::Iterator it;
    for(it=limite.begin();it!=limite.end();it++)
    {
        if((*it)->collidesWithItem(air))
            return true;
    }
    return false;
}

//bool Juego::ColMil_lim()
//{
//    QList<Limites*>::Iterator it;
//    if((*it)->collidesWithItem(misil1)){
//        return true;
//    }
//    else
//        return false;
//}




