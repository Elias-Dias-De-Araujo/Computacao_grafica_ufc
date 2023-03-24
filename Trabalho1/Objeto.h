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
    virtual void desenha();
    Objeto(int ident, float t_x, float t_y, float t_z,
                   float r_x, float r_y, float r_z,
                   float e_x, float e_y, float e_z,
                   bool sel, bool cl);


};


#endif // OBJETO_H
