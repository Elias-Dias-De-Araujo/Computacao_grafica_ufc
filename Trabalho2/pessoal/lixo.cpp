#include "lixo.h"

Lixo::Lixo(int ident, float t_x, float t_y, float t_z,
               float r_x, float r_y, float r_z,
               float e_x, float e_y, float e_z,
               bool sel, bool cl) {
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
    model = new Model3DS("../3ds/trash.3ds");
}


void Lixo::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if(cord_local){
            GUI::drawOrigin(1);
        }

        GUI::setColor(0.85705,0.13333,0.18431);

        if (selecionado) {

            GUI::setColor(1.0,1.0,1.0);
        }

        glScalef(1, 1, 1);
        glTranslatef(0,0,0);
        glRotatef(-90,1,0,0);
        glScalef(0.01, 0.01, 0.01);
        model->draw(false);

    glPopMatrix();

}
