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

void Juego::ayuda()
{
    help = new QGraphicsScene ;
    help->setSceneRect(0,0,736,414);
    help->setBackgroundBrush(QImage(":/images/help").scaled(736,414));
}

void Juego::Funlimites(int nivel)
{
    limite.push_back(new Limites(0,0,736,10));
    if(nivel==1)
        mundo1->addItem(limite.back());
    else if(nivel==2)
        mundo2->addItem(limite.back());
    limite.push_back(new Limites(0,0,10,414));
    if(nivel==1)
        mundo1->addItem(limite.back());
    else if(nivel==2)
        mundo2->addItem(limite.back());
    limite.push_back(new Limites(368,0,10,414));
    if(nivel==1)
        mundo1->addItem(limite.back());
    else if(nivel==2)
        mundo2->addItem(limite.back());
    limite.push_back(new Limites(0,207,736,10));
    if(nivel==1)
        mundo1->addItem(limite.back());
    else if(nivel==2)
        mundo2->addItem(limite.back());
}

void Juego::nivel_1(int nivel)
{
    nivel=1;
    mundo1 = new QGraphicsScene;
    mundo1->setSceneRect(0,0,736,414);
    mundo1->setBackgroundBrush(QImage(":/images/video_preview_0000.jpg").scaled(736,414));

    air=new Avion(15,15,46,13);
    mundo1->addItem(air);

    //    manejoColisione();
}

void Juego::nivel_2(int nivel)
{
    nivel=2;
    mundo2 = new QGraphicsScene;
    mundo2->setSceneRect(0,0,736,414);
    mundo2->setBackgroundBrush(QImage(":/images/nivel2.jpg").scaled(736,414));

    air=new Avion(15,15,46,13);
    mundo2->addItem(air);
}

void Juego::act_misil(int x, int y) // ACTIVAR MISIL
{
    misil1=new Misil(x,y,15);
    mundo1->addItem(misil1);
}

void Juego::act_bfuego(int y,int nivel,int nbolas)
{
    if(nivel==1){
        BFuego = new Bolafuego(240, y, 15,15, nivel,nbolas);
        bolasf.insert(nbolas, BFuego);
        mundo1->addItem(BFuego);
    }
    else if(nivel==2){
        BFuego = new Bolafuego(240, y, 15,15, nivel,nbolas);
        bolasf.insert(nbolas, BFuego);
        mundo2->addItem(BFuego);
    }
/*    BFuego=new Bolafuego(240, y, 15, nivel);
 *
//    bolasf.push_back(BFuego);
//    mundo1->addItem(bolasf.back());

//    bolasf.push_back(new Bolafuego(240,y,15,nivel)); //Falla con append y push_back
//    mundo1->addItem(bolasf.back());

//    BFuego=new Bolafuego(240,y,15,nivel);
//    mundo1->addItem(BFuego);
    }
}*/
}

bool Juego::ColAv_BolasF(int nbolas,int nivel)
{
    if (bolasf.value(nbolas)->collidesWithItem(air)){
        if(nivel==1){
            mundo1->removeItem(bolasf.value(nbolas));
            bolasf.remove(nbolas);
            return true;
        }
        else if(nivel==2){
            mundo2->removeItem(bolasf.value(nbolas));
            bolasf.remove(nbolas);
            return true;
        }
//        delete bolasf[nbolas];
    }
    if (bolasf.value(nbolas)->getPosx()==-10 ){
        if(nivel==1){
            mundo1->removeItem(bolasf.value(nbolas));
            bolasf.remove(nbolas);
        }
        else if(nivel==2){
            mundo2->removeItem(bolasf.value(nbolas));
            bolasf.remove(nbolas);
        }
    }

    return false;

/*    QList<Bolafuego*>::iterator it;  // Cambio de QList<Bolafuego*>::iterator a QList<Bolafuego>::iterator
//    for (it = bolasf.begin(); it != bolasf.end(); it++) {
//        if (air->collidesWithItem((*it))) {
//            return true;
//        }
//    }
//    QList<Bolafuego*>::iterator it;
//    for (it = bolasf.begin(); it != bolasf.end(); it++) {
//        if(air->collidesWithItem(*it)){
//            return true;
//        }
//    }
//    return false;
*/
}

void Juego::act_bala(int y,int nbalas,int nivel)
{
    balas=new Bala(240,y,40,15,nivel);
    balasmap.insert(nbalas, balas);
    if (nivel==1)
        mundo1->addItem(balas);
    else if (nivel==2){
        mundo2->addItem(balas);
    }
}

bool Juego::ColAv_Bala(int nbalas,int nivel)
{
    if (balasmap.value(nbalas)->collidesWithItem(air)){
        if(nivel==1){
            mundo1->removeItem(balasmap.value(nbalas));
            balasmap.remove(nbalas);
            return true;
        }
        else if(nivel==2){
            mundo2->removeItem(balasmap.value(nbalas));
            balasmap.remove(nbalas);
            return true;
        }
    }
    if (balasmap.value(nbalas)->getPosx()==0){
        if(nivel==1){
            mundo1->removeItem(balasmap.value(nbalas));
            balasmap.remove(nbalas);
        }
        else if (nivel==2){
            mundo2->removeItem(balasmap.value(nbalas));
            balasmap.remove(nbalas);
        }
    }
    return false;
}

bool Juego::ColAv_lim() //COLISION AVION CONTRA LIMITES DEL JUEGO - 342
{
    QList<Limites*>::Iterator it;
    for(it=limite.begin();it!=limite.end();it++)
    {
        if((*it)->collidesWithItem(air))
            return true;
    }
    return false;
}

/*void Juego::Act_MovFuego() NO CONECTÓ DESDE JUEGO A MAINWINDOW
//{
//    bolasf.back()->MovRectilineo();
//    bolasf.back()->setPos(bolasf.back()->getPosx(),bolasf.back()->getPosy());
//}*/



/*void Juego::manejoColisione()
//{
//    if(!bolasf.empty()){
//        int contador=0;
//        QList<Bolafuego*>::iterator it;
//        for (it = bolasf.begin(); it != bolasf.end(); it++) {
//            if(ColAv_BolasF()){
//                mundo1->removeItem(bolasf.at(contador));
//                bolasf.removeAt(contador);
//                break;
//            }
//            contador++;
//        }
//    }
//}
*/





