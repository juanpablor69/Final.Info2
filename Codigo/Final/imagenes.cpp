#include "imagenes.h"
#include <QGraphicsItem>

Imagenes::Imagenes()
{

}

Imagenes::Imagenes(int x, int y, int _an, int _h, int name_img)
{
    this->posx=x;
    this->posy=y;
    this->an=_an;
    this->h=_h;
    this->image=name_img;
    setPos(posx,posy);

}
