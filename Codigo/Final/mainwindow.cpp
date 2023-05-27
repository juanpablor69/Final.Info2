#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GAME=new Juego;
    vermenu(); //Inicializa el juego
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
    menu->setBackgroundBrush(QImage(":/menu1/menu2.jpg"));
}

//void MainWindow::nivel_1()
//{
//    mundo1 = new QGraphicsScene;
//    mundo1->setSceneRect(0,0,736,414);
//    mundo1->setBackgroundBrush(QImage(":/menu1/video_preview_0000.jpg").scaled(736,414));

//    air=new Avion(15,15,30);
//    mundo1->addItem(air);
//}


void MainWindow::on_nivel1_clicked()
{
//    mundo1 = new QGraphicsScene;
//    mundo1->setSceneRect(0,0,736,414);
//    mundo1->setBackgroundBrush(QImage(":/menu1/video_preview_0000.jpg").scaled(736,414));

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
}


