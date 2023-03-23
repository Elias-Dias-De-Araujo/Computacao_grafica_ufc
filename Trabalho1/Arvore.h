#ifndef ARVORE_H
#define ARVORE_H

#include <Objeto.h>

using namespace std;

class Arvore : public Objeto
{
public:
    Arvore(
            float t_x, float t_y, float t_z,
            float r_x, float r_y, float r_z,
            float e_x, float e_y, float e_z,
            bool sel, bool cl
            );
    void criar();
    void desenha();
};

#endif // ARVORE_H
