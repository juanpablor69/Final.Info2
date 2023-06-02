#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QTimer>
#include <QList>
#include <cstdlib>

#include "juego.h"
#include "avion.h"
#include "misil.h"
#include "limites.h"
#include "bolafuego.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *menu, *mundo1;
    Juego *GAME;
    QTimer *timer;
    QTimer *timer_Bfuego;

    int posXAv,posYAv; // Posicion del avion

//    QList< CLASE *>::iterator it;
//    for(it=NOMBRE LISTA.begin();it!=NOMBRE LISTA.end();it++)
//    {
//        if(bala->collidesWithItem(*it))
//        {
//            return true;
//        }
//    }

    void vermenu();
    void vernivel1();
    void escena_Menu(); //Funcion para configurar el menu
    void nivel_1();
    void act_misil();
    void mostrar();

    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
