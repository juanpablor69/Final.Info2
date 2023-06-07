#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QTimer>
#include <QList>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <QMessageBox>

#include "juego.h"
#include "avion.h"
#include "misil.h"
#include "limites.h"
#include "bolafuego.h"
#include "bala.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_nivel1_clicked();
    void Actualizar();
    void Act_MovFuego();
    void Act_MovBala();
    void crono();

    void on_perdiste_clicked();

    void on_nivel2_clicked();

    void on_ganaste_clicked();

    void on_ayuda_clicked();

    void on_menu_clicked();

private:
    Ui::MainWindow *ui;
//    QGraphicsScene *menu, *mundo1;
    Juego *GAME;
    Bolafuego *BFuego;

    QTimer *timer;
    QTimer *timer_Bfuego;
    QTimer *contador1;
    QTimer *tbalas;
//    QList<Bolafuego*>bolasf;

    int posXAv,posYAv; // Posicion del avion
    int seg=0,min=0;
    int nivel=0,puntaje=0,conlista=0;
    int nbfuego=0,nbalas=0, coli=0;

    void keyPressEvent(QKeyEvent *evento);
    void vermenu();
    void vernivel1();
    void escena_Menu(); //Funcion para configurar el menu
    void nivel_1();
    void act_misil();
    void mostrar();
    void ColAvBFuegoMain();
    void DetColi();
    void ActBola(int y,int nivel);
    void Actpuntaje(int seg);
    void verayuda();

};
#endif // MAINWINDOW_H
