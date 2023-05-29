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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vermenu()
{
    GAME->escena_Menu();
    ui->graphicsView->setScene(GAME->menu);
}

void MainWindow::escena_Menu()
{
    menu = new QGraphicsScene ;
    menu->setSceneRect(0,0,736,414);
    menu->setBackgroundBrush(QImage(":/images/menu2.jpg"));
}

void MainWindow::on_nivel1_clicked()
{
    ui->nivel1->hide();

    GAME->nivel_1();
    ui->graphicsView->setScene(GAME->mundo1);
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W)
        GAME->air->MovArriba();
    else if(evento->key()==Qt::Key_S)
        GAME->air->MovAbajo();
    else if(evento->key()==Qt::Key_Q)
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

