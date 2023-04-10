#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::desenha() {
    // T.Rz.Ry.Rx.S (correspondente ao T'' da Q1 da lista 1)
    glTranslatef(trans_x,trans_y,trans_z); //transformacao (matriz) mais a esquerda (mais global)
    glRotatef(rot_x,0,0,1);  // \ .
    glRotatef(rot_y,0,1,0);  //  | Rz.Ry.Rx . v
    glRotatef(rot_z,1,0,0);  // /
    glScalef(esca_x,esca_y,esca_z); //transformacao (matriz) mais a direita (mais local)
}
