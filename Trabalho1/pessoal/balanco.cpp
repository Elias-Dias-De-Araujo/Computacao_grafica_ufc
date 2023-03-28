#include "balanco.h"

Balanco::Balanco(int ident, float t_x, float t_y, float t_z,
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
    model = new Model3DS("../3ds/swing.3ds");
}


void Balanco::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if(cord_local){
            GUI::drawOrigin(1);
        }

        GUI::setColor(0.5,0.5,0.5);

        if (selecionado) {

            GUI::setColor(1.0,1.0,1.0);
        }

        glTranslatef(0,0,0);
        glRotatef(-90,1,0,0);
        glScalef(1, 1, 1);
        glScalef(0.0005, 0.0009, 0.0009);
        model->draw(!selecionado); //se estiver selecionado, tem que desenhar o modelo 3ds
                                   //não colorido internamente para que a cor de destaque
                                   //da seleção tenha efeito
    glPopMatrix();

}
