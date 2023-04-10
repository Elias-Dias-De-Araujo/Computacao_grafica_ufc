#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto
{
public:
    int identifier;
    float trans_x, trans_y, trans_z;
    float rot_x, rot_y, rot_z;
    float esca_x, esca_y, esca_z;
    bool selecionado;
    bool cord_local;
public:
    Objeto();
    virtual void desenha();
};

#endif // OBJETO_H
