#ifndef PARABOLICO_H
#define PARABOLICO_H

#include <math.h>

#define tiempo 0.01

class Parabolico
{
    double posx,posy,velocidad, angulo,velx,vely;
public:
    Parabolico();
    Parabolico(double x, double y,double v, double a);
    void CalcularVelocidad();
    void CalcularPosicion();
    void ActualizarVelocidad();

    double getPosx() const;
    double getPosy() const;
};

#endif // PARABOLICO_H
