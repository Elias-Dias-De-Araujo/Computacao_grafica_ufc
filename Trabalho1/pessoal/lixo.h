#ifndef LIXO_H
#define LIXO_H


#include <objeto.h>

class Lixo : public Objeto
{
public:
    Model3DS* model;
public:
    Lixo(
            int ident, float t_x, float t_y, float t_z,
            float r_x, float r_y, float r_z,
            float e_x, float e_y, float e_z,
            bool sel, bool cl
            );
    void desenha();
};

#endif // LIXO_H
