#ifndef TENDA_H
#define TENDA_H

#include <Objeto.h>

using namespace std;

class Tenda : public Objeto
{
public:
    Tenda(
            float t_x, float t_y, float t_z,
            float r_x, float r_y, float r_z,
            float e_x, float e_y, float e_z,
            bool sel, bool cl
            );
    void criar();
    void desenhar_objeto();
};


#endif // TENDA_H
