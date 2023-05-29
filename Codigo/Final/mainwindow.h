﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QTimer>

#include "juego.h"
#include "avion.h"
#include "misil.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *menu, *mundo1;
    Juego *GAME;
    QTimer *timer;

    void vermenu();
    void vernivel1();
    void escena_Menu(); //Funcion para configurar el menu
    void nivel_1();
    void act_misil();
    int posXAv,posYAv;
    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
