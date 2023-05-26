#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GAME=new Juego;
    vermenu(); //Muestra el menu
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

void MainWindow::on_nivel1_clicked()
{
    ui->nivel1->hide();
    GAME->nivel_1();
    ui->graphicsView->setScene(GAME->mundo1);
}

