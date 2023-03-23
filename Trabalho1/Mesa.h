#ifndef MESA_H
#define MESA_H
#include <Objeto.h>

using namespace std;


class Mesa:public Objeto{
public:
    Mesa(
            float t_x, float t_y, float t_z,
            float r_x, float r_y, float r_z,
            float e_x, float e_y, float e_z,
            bool sel, bool cl
            );
    void criar();
    void desenhar_objeto();

};

#endif // MESA_H
