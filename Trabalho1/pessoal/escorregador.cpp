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

        glBegin(GL_POLYGON);
            glNormal3f(0,-1,0);
            glVertex3f(-0.4,1,0.5);
            glVertex3f(-0.4,1,-0.1);
            glVertex3f(0.4,1,-0.1);
            glVertex3f(0.4,1,0.5);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glVertex3f(0.4,1,0.6);
            glVertex3f(0.4,1,-0.1);
            glVertex3f(0.4,1.1,-0.1);
            glVertex3f(0.4,1.1,0.6);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(-1,0, 0);
            glVertex3f(0.4,1.1,0.6);
            glVertex3f(0.4,1.1,-0.1);
            glVertex3f(0.4,1,-0.1);
            glVertex3f(0.4,1,0.6);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glVertex3f(-0.4,1,0.6);
            glVertex3f(-0.4,1,-0.1);
            glVertex3f(-0.4,1.1,-0.1);
            glVertex3f(-0.4,1.1,0.6);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glVertex3f(-0.4,1.1,0.6);
            glVertex3f(-0.4,1.1,-0.1);
            glVertex3f(-0.4,1,-0.1);
            glVertex3f(-0.4,1,0.6);
        glEnd();

        // base inclinada
        glBegin(GL_POLYGON);
            glNormal3f(0,1,1);
            glVertex3f(0.4,0.1,0.8);
            glVertex3f(0.4,1,0.5);
            glVertex3f(-0.4,1,0.5);
            glVertex3f(-0.4,0.1,0.8);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(0,-1,-1);
            glVertex3f(-0.4,0.1,0.8);
            glVertex3f(-0.4,1,0.5);
            glVertex3f(0.4,1,0.5);
            glVertex3f(0.4,0.1,0.8);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glVertex3f(0.4,0.1,0.8);
            glVertex3f(0.4,1,0.5);
            glVertex3f(0.4,1,0.6);
            glVertex3f(0.4,0.1,0.9);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glVertex3f(0.4,0.1,0.9);
            glVertex3f(0.4,1,0.6);
            glVertex3f(0.4,1,0.5);
            glVertex3f(0.4,0.1,0.8);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glVertex3f(-0.4,0.1,0.8);
            glVertex3f(-0.4,1,0.5);
            glVertex3f(-0.4,1,0.6);
            glVertex3f(-0.4,0.1,0.9);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glVertex3f(-0.4,0.1,0.9);
            glVertex3f(-0.4,1,0.6);
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

        glBegin(GL_POLYGON);
            glNormal3f(0,-1,0);
            glVertex3f(-0.4,0.1,1.2);
            glVertex3f(-0.4,0.1,0.8);
            glVertex3f(0.4,0.1,0.8);
            glVertex3f(0.4,0.1,1.2);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glVertex3f(0.4,0.1,1.2);
            glVertex3f(0.4,0.1,0.8);
            glVertex3f(0.4,0.2,0.85);
            glVertex3f(0.4,0.2,1.2);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glVertex3f(0.4,0.2,1.2);
            glVertex3f(0.4,0.2,0.85);
            glVertex3f(0.4,0.1,0.8);
            glVertex3f(0.4,0.1,1.2);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glVertex3f(-0.4,0.1,1.2);
            glVertex3f(-0.4,0.1,0.8);
            glVertex3f(-0.4,0.2,0.85);
            glVertex3f(-0.4,0.2,1.2);
        glEnd();

        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glVertex3f(-0.4,0.2,1.2);
            glVertex3f(-0.4,0.2,0.85);
            glVertex3f(-0.4,0.1,0.8);
            glVertex3f(-0.4,0.1,1.2);
        glEnd();

        // pilares
        GUI::drawBox(-0.4,0,0.45, -0.38,1,0.5);
        GUI::drawBox(0.38,0,0.45, 0.4,1,0.5);
        GUI::drawBox(-0.05,0,0.98, 0.05,0.1,1);

        // degraus
        GUI::drawBox(-0.25,0.20,-0.15, 0.25,0.25,-0.1);
        GUI::drawBox(-0.25,0.50,-0.15, 0.25,0.55,-0.1);
        GUI::drawBox(-0.25,0.80,-0.15, 0.25,0.85,-0.1);

        // laterais
        GUI::drawBox(0.25,0,-0.15, 0.40,1,-0.1);
        GUI::drawBox(-0.40,0,-0.15, -0.25,1,-0.1);

    glPopMatrix();

}
