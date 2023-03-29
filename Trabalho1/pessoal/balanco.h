#ifndef BALANCO_H
#define BALANCO_H

#include <objeto.h>

class Balanco : public Objeto
{
public:
    Balanco(
            int ident, float t_x, float t_y, float t_z,
            float r_x, float r_y, float r_z,
            float e_x, float e_y, float e_z,
            bool sel, bool cl
            );
    void desenha();
};
#endif // BALANCO_H
