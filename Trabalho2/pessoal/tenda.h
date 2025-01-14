#ifndef TENDA_H
#define TENDA_H

#include <objeto.h>

class Tenda : public Objeto
{
public:
    Tenda(
            int ident, float t_x, float t_y, float t_z,
            float r_x, float r_y, float r_z,
            float e_x, float e_y, float e_z,
            bool sel, bool cl
            );
    void criar();
    void desenha();
};

#endif // TENDA_H
