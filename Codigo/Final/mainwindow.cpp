#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GAME=new Juego;
    vermenu(); //Inicializa el juego
    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer_Bfuego= new QTimer();
    connect(timer_Bfuego,SIGNAL(timeout()),this,SLOT(Act_MovFuego()));
    contador1=new QTimer();
    connect(contador1,SIGNAL(timeout()),this,SLOT(crono()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vermenu()
{
    GAME->escena_Menu();
    ui->graphicsView->setScene(GAME->menu);
    ui->cronometro->hide();
}

void MainWindow::escena_Menu()
{
    menu = new QGraphicsScene ;
    menu->setSceneRect(0,0,736,414);
    menu->setBackgroundBrush(QImage(":/images/menu2.jpg"));
}

//void MainWindow::mostrar()
//{
//    if(GAME->ColMil_lim())
//        ui->nivel1->hide();
//}

void MainWindow::on_nivel1_clicked()
{
    ui->titulo->hide();
    ui->nivel1->hide();
    ui->nivel2->hide();
    ui->cronometro->show();
    GAME->nivel_1();
    nivel=1;
    ui->graphicsView->setScene(GAME->mundo1);
    GAME->Funlimites();
    crono();
//    if(GAME->ColMil_lim()){
//        ui->nivel1->hide();
//    }
//    mostrar();

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W) //Arriba
    {
        if (!GAME->ColAv_lim()){
            GAME->air->MovArriba();
        }
        else
            GAME->air->MovAbajo();
    }
    else if(evento->key()==Qt::Key_S) //Abajo
    {
        if (!GAME->ColAv_lim())
            GAME->air->MovAbajo();
        else
            GAME->air->MovArriba();
    }
    else if(evento->key()==Qt::Key_Q) // ACTIVAR MISIL
    {
        posXAv=(GAME->air->getPosx())+5;
        posYAv=(GAME->air->getPosy())+5;
        GAME->act_misil(posXAv,posYAv);
        timer->start(10);
    }
}

void MainWindow::Actualizar()
{
    GAME->misil1->CalcularVelocidad();
    GAME->misil1->CalcularPosicion();
    GAME->misil1->ActualizarVelocidad();
    GAME->misil1->setPos(GAME->misil1->getPosx(),GAME->misil1->getPosy());
}

void MainWindow::Act_MovFuego()
{
    GAME->BFuego->MovRectilineo();
    GAME->BFuego->setPos(GAME->BFuego->getPosx(),GAME->BFuego->getPosy());
}

void MainWindow::crono()
{
    seg++;
    if (seg==60){
        min++;
        seg=0;
    }
    if (seg%7==0){
        posYAv=5+(GAME->air->getPosy());
        GAME->act_bfuego(posYAv,nivel);
        timer_Bfuego->start(10);
    }
    contador1->start(1000);
    QString texto = QString("%1:%2").arg(min).arg(seg);
    ui->cronometro->setText(texto);
}

//bool MainWindow::evaluarColisionBullet2(Misil *misil)
//{
//    QList<Limites*>::iterator it;
//    for(it=limite.begin();it!=misil.end();it++)
//    {
//        if(bala->collidesWithItem(*it))
//        {
//            return true;
//        }
//    }
