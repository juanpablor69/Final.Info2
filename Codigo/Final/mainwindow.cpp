#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GAME=new Juego;
    vermenu(); //Inicializa el juego

    timer= new QTimer(); //MISIL
    connect(timer,SIGNAL(timeout()),this,SLOT(Actualizar()));

//    timer_Bfuego = new QTimer(GAME); //BOLAS DE FUEGO
//    connect(timer_Bfuego, SIGNAL(timeout()), GAME, SLOT(Act_MovFuego()));

    timer_Bfuego= new QTimer(); //BOLAS DE FUEGO
    connect(timer_Bfuego,SIGNAL(timeout()),this,SLOT(Act_MovFuego()));

    contador1=new QTimer(); //CRONOMETRO
    connect(contador1,SIGNAL(timeout()),this,SLOT(crono()));
}

void MainWindow::vermenu()
{
    GAME->escena_Menu();
    ui->graphicsView->setScene(GAME->menu);
    ui->cronometro->hide();
    ui->perdiste->hide();
    ui->nivel1->show();
    ui->nivel2->show();
    ui->puntaje->hide();
    ui->label_col->hide();
}

void MainWindow::escena_Menu()
{
    menu = new QGraphicsScene ;
    menu->setSceneRect(0,0,736,414);
    menu->setBackgroundBrush(QImage(":/images/menu2.jpg"));
}

void MainWindow::on_nivel1_clicked()
{
    ui->titulo->hide();
    ui->nivel1->hide();
    ui->nivel2->hide();
    ui->puntaje->show();
    ui->cronometro->show();
        ui->label_col->show();
    GAME->nivel_1();
    nivel=1;
    ui->graphicsView->setScene(GAME->mundo1);
//    GAME->Funlimites();
    crono();
    GAME->Funlimites();
}

void MainWindow::on_nivel2_clicked()
{
    seg=0;
    nivel=2;
    GAME->nivel_2();
    ui->graphicsView->setScene(GAME->mundo2);
    ui->titulo->hide();
    ui->nivel1->hide();
    ui->nivel2->hide();
    ui->puntaje->show();
    ui->cronometro->show();
    ui->label_col->show();
    ui->lista->show();
    GAME->Funlimites();
    crono();
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
    else if(evento->key()==Qt::Key_D)
    {
        if (!GAME->ColAv_lim())
            GAME->air->MovDerecha();
    }
    else if(evento->key()==Qt::Key_Q) // ACTIVAR MISIL
    {
        posXAv=(GAME->air->getPosx())+5;
        posYAv=(GAME->air->getPosy())+5;
        GAME->act_misil(posXAv,posYAv);
        timer->start(10);
    }
}

void MainWindow::Act_MovFuego()
{
    if (!GAME->bolasf.isEmpty()) { // SI LISTA NO ESTA VACIA
        // Obtener el iterador al último elemento del mapa
        auto lastIterator = --GAME->bolasf.end();

        // Acceder al puntero al último objeto Bolafuego
        Bolafuego* bolafuego = lastIterator.value();

        // Realizar las operaciones necesarias
        bolafuego->MovRectilineo();
        bolafuego->setPos(bolafuego->getPosx(), bolafuego->getPosy());
        if(GAME->ColAv_BolasF(nbfuego)){
            coli++;
            QString col = QString("Coli %1").arg(coli);
            ui->label_col->setText(col);
            puntaje-=80; //PENA POR COLISION
        }
    }else{ //AUMENTA SI HAY ERROR EN LISTA
        conlista++;
        QString listaS = QString("LVacia %1").arg(conlista);
//        QString listaS = QString("nivel %1").arg(nivel);
        ui->lista->setText(listaS);
    }

//    GAME->bolasf.back()->MovRectilineo();
//    GAME->bolasf.back()->setPos(bolasf.back()->getPosx(),bolasf.back()->getPosy());

//    if (GAME->bolasf.isEmpty()) {
//        GAME->bolasf.back()->MovRectilineo();
//        GAME->bolasf.back()->setPos(GAME->bolasf.back()->getPosx(), GAME->bolasf.back()->getPosy());
//    }else{
//       conlista++;
//       QString listaS = QString("%1").arg(conlista);
//       ui->lista->setText(listaS);
//    }

//    bolasf.MovRectilineo();
//    GAME->BFuego->setPos(GAME->BFuego->getPosx(),GAME->BFuego->getPosy());

//    if(GAME->ColAv_BolasF()){
//        puntaje++;
//        QString puntaje1 = QString("Puntaje: %1").arg(puntaje);
//        ui->cronometro->setText(puntaje1);
//    }
}

void MainWindow::Actualizar()
{
    GAME->misil1->CalcularVelocidad();
    GAME->misil1->CalcularPosicion();
    GAME->misil1->ActualizarVelocidad();
    GAME->misil1->setPos(GAME->misil1->getPosx(),GAME->misil1->getPosy());
}

void MainWindow::crono()
{
    seg++;
    if (seg==60){
        min++;
        seg=0;
    }
    if (seg%7==0){
        nbfuego++;
        posYAv=(GAME->air->getPosy());
        GAME->act_bfuego(posYAv,nivel,nbfuego);
        timer_Bfuego->start(10);
    }
    contador1->start(1000);
    QString texto = QString("%1:%2").arg(min).arg(seg);
    ui->cronometro->setText(texto);
    Actpuntaje(seg);
}

void MainWindow::Actpuntaje(int seg)
{
    if(seg>0){
        puntaje=puntaje+(((seg+2)/2)/4);
        QString puntajeS = QString("Puntaje: %1").arg(puntaje);
        ui->puntaje->setText(puntajeS);
    }
    if(puntaje<0){
        seg=0;
        puntaje=0;
        ui->perdiste->show();
        timer_Bfuego->stop();
        contador1->stop();
        GAME->air->hide();
//        if(nivel==1){
//            mundo1->removeItem(GAME->air);
//            delete GAME->air;
//        }
    }
}

void MainWindow::on_perdiste_clicked()
{
    vermenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::ActBola(int y,int nivel)
//{
//    Bolafuego bolafuego(240, y, 15, nivel);
//    bolasf.push_back(bolafuego);
//    mundo1->addItem(&bolasf.back());

//    bolasf.push_back(new Bolafuego(240,y,15,nivel); //Falla con append y push_back
//    mundo1->addItem(bolasf.back());

//    bolasf.back()->MovRectilineo();
//    bolasf.back()->setPos(bolasf.back()->getPosx(),bolasf.back()->getPosy());

//    BFuego=new Bolafuego(240,y,15,nivel);
//    mundo1->addItem(BFuego);
//}

//void MainWindow::ColAvBFuegoMain()
//{
//    if(GAME->ColAv_BolasF()){
//        puntaje++;
//        QString puntaje1 = QString("Puntaje: %1").arg(puntaje);
//        ui->cronometro->setText(puntaje1);
//    }
//}

