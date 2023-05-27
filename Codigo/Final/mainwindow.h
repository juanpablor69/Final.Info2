﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>

#include "juego.h"
#include "avion.h"

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *menu, *mundo1;
    Juego *GAME;

    void vermenu();
    void vernivel1();
    void escena_Menu(); //Funcion para configurar el menu
    void nivel_1();
    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
