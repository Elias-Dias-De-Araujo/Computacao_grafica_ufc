#include "escorregador.h"

Escorregador::Escorregador(int ident, float t_x, float t_y, float t_z,
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
    //model = new Model3DS("../3ds/slide.3DS");
}


void Escorregador::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if(cord_local){
            GUI::drawOrigin(1);
        }

        GUI::setColor(0.74117,0.92549,0.71372);

        if (selecionado) {

            GUI::setColor(1.0,1.0,1.0);
        }

        // base superior
        glBegin(GL_POLYGON);
            glNormal3f(0,1,0);
            glVertex3f(0.4,1,0.5);
            glVertex3f(0.4,1,-0.1);
            glVertex3f(-0.4,1,-0.1);
            glVertex3f(-0.4,1,0.5);
        glEnd();

        // base inclinada
        glBegin(GL_POLYGON);
            glNormal3f(0,1,1);
            glVertex3f(0.4,0.1,0.8);
            glVertex3f(0.4,1,0.5);
            glVertex3f(-0.4,1,0.5);
            glVertex3f(-0.4,0.1,0.8);
        glEnd();

        // base inferior
        glBegin(GL_POLYGON);
            glNormal3f(0,1,0);
            glVertex3f(0.4,0.1,1.2);
            glVertex3f(0.4,0.1,0.8);
            glVertex3f(-0.4,0.1,0.8);
            glVertex3f(-0.4,0.1,1.2);
        glEnd();

        //GUI::drawBox(-0.4,0.95,-0.1, 0.4,1,0.5);

        // degraus
        GUI::drawBox(-0.25,0.20,-0.15, 0.25,0.25,-0.1);
        GUI::drawBox(-0.25,0.50,-0.15, 0.25,0.55,-0.1);
        GUI::drawBox(-0.25,0.80,-0.15, 0.25,0.85,-0.1);

        // laterais
        GUI::drawBox(0.25,0,-0.15, 0.40,1,-0.1);
        GUI::drawBox(-0.40,0,-0.15, -0.25,1,-0.1);

//        glTranslatef(0,0,0);
//        glRotatef(-90,0,1,0);
//        glRotatef(-90,1,0,0);
//        glScalef(1, 1, 1);
//        glScalef(0.0005, 0.0005, 0.0005);
//        model->draw(false); //se estiver selecionado, tem que desenhar o modelo 3ds
//                                   //não colorido internamente para que a cor de destaque
//                                   //da seleção tenha efeito
    glPopMatrix();

}
