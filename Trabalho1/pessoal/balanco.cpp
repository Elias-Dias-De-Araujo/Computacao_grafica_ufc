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
    //model = new Model3DS("../3ds/swing.3ds");
}


void Balanco::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if(cord_local){
            GUI::drawOrigin(1);
        }

        GUI::setColor(0.87058,0.72156,0.52941);

        if (selecionado) {

            GUI::setColor(1.0,1.0,1.0);
        }

        // madeira cima
        GUI::drawBox(-0.75,0.9,-0.05, 0.75,1,0.05);

        GUI::setColor(1,1,1);
        // cabos centro
        GUI::drawBox(-0.26,0.4,-0.005, -0.25,0.9,0.005);
        GUI::drawBox(0.25,0.4,-0.005, 0.26,0.9,0.005);

        GUI::setColor(0.87058,0.72156,0.52941);
        if (selecionado) {

            GUI::setColor(1.0,1.0,1.0);
        }

        // bancada
        GUI::drawBox(-0.30,0.4,-0.1, 0.30,0.42,0.1);

        // madeiras laterais
        GUI::drawBox(0.75,0,-0.1, 0.9,1,0.1);
        GUI::drawBox(-0.9,0,-0.1, -0.75,1,0.1);


//        glTranslatef(0,0,0);
//        glRotatef(-90,1,0,0);
//        glScalef(1, 1, 1);
//        glScalef(0.0005, 0.0009, 0.0009);
//        model->draw(false); //se estiver selecionado, tem que desenhar o modelo 3ds
//                                   //não colorido internamente para que a cor de destaque
//                                   //da seleção tenha efeito
    glPopMatrix();

}
