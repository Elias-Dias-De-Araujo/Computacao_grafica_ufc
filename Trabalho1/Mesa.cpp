#include "Mesa.h"
#include <gui.h>

using namespace std;

Mesa::Mesa(int ident, float t_x, float t_y, float t_z,
               float r_x, float r_y, float r_z,
               float e_x, float e_y, float e_z,
               bool sel, bool cl) : Objeto(ident, t_x,  t_y,  t_z,
                                                      r_x,  r_y,  r_z,
                                                      e_x,  e_y,  e_z,
                                                      sel,  cl){
}

void Mesa::criar(){
    if(cord_local){
        GUI::drawOrigin(1);
    }

    GUI::setColor(0.1843,0.2,0.1961, 1,true);


    if(selecionado) {
       GUI::setColor(1,1,1, 1,true);
    }

    // Base
    // Face Frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0.25,0,0);
        glVertex3f(0.25,0.5,0);
        glVertex3f(0,0.5,0);
    glEnd();

    // Face Trás
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-0.25);
        glVertex3f(0,0,-0.25);
        glVertex3f(0,0.5,-0.25);
        glVertex3f(0.25,0.5,-0.25);
        glVertex3f(0.25,0,-0.25);
    glEnd();

    // Face Direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.25,0,0);
        glVertex3f(0.25,0,-0.25);
        glVertex3f(0.25,0.5,-0.25);
        glVertex3f(0.25,0.5,0);
    glEnd();

    // Face Esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0.5,0);
        glVertex3f(0,0.5,-0.25);
        glVertex3f(0,0,-0.25);
    glEnd();

    // Face Chão
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-0.25);
        glVertex3f(0.25,0,-0.25);
        glVertex3f(0.25,0,0);
    glEnd();

    // Fim Da Base

    // Quadrado

    //Face Cima
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(0.5,0.75,0.25);
        glVertex3f(0.5,0.75,-0.5);
        glVertex3f(-0.25,0.75,-0.5);
        glVertex3f(-0.25,0.75,0.25);
    glEnd();

    //Face Frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.25,0.5,0.25);
        glVertex3f(0.5,0.5,0.25);
        glVertex3f(0.5,0.75,0.25);
        glVertex3f(-0.25,0.75,0.25);
    glEnd();

    //Face Trás
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(-0.25,0.5,-0.5);
        glVertex3f(-0.25,0.75,-0.5);
        glVertex3f(0.5,0.75,-0.5);
    glEnd();

    //Face Direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0.5,0.25);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,0.75,-0.5);
        glVertex3f(0.5,0.75,0.25);
    glEnd();

    //Face Esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(-0.25,0.5,-0.5);
        glVertex3f(-0.25,0.5,0.25);
        glVertex3f(-0.25,0.75,0.25);
        glVertex3f(-0.25,0.75,-0.5);
    glEnd();

    //Face Baixo
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0.5,0.5,-0.5);
        glVertex3f(0.5,0.5,0.25);
        glVertex3f(-0.25,0.5,0.25);
        glVertex3f(-0.25,0.5,-0.5);
    glEnd();
}

void Mesa::desenha(){
    glPushMatrix();
        Objeto::desenha(); // T.Rz.Ry.Rx.S. p
        criar();
    glPopMatrix();

}

