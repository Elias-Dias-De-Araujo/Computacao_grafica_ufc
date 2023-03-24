#include <fstream>
#include "Objeto.h"
#include <gui.h>


using namespace std;


Objeto::Objeto(int ident, float t_x, float t_y, float t_z,
               float r_x, float r_y, float r_z,
               float e_x, float e_y, float e_z,
               bool sel, bool cl){
    identifier = ident;
    trans_x = t_x;
    trans_y = t_y;
    trans_z = t_z;
    rot_x = r_x;
    rot_y = r_y;
    rot_z = r_z;
    esca_x = e_x;
    esca_y = e_y;
    esca_z = e_z;
    selecionado = sel;
    cord_local = cl;
}

void Objeto::desenha() {
    // T.Rz.Ry.Rx.S (correspondente ao T'' da Q1 da lista 1)
    glTranslatef(trans_x,trans_y,trans_z); //transformacao (matriz) mais a esquerda (mais global)
    glRotatef(rot_x,0,0,1);  // \ .
    glRotatef(rot_y,0,1,0);  //  | Rz.Ry.Rx . v
    glRotatef(rot_z,1,0,0);  // /
    glScalef(esca_x,esca_y,esca_z); //transformacao (matriz) mais a direita (mais local)
}






