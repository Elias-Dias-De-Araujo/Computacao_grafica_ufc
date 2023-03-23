#include "Arvore.h"
#include <gui.h>

using namespace std;

Arvore::Arvore(float t_x, float t_y, float t_z,
               float r_x, float r_y, float r_z,
               float e_x, float e_y, float e_z,
               bool sel, bool cl){
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

void Arvore::criar(){
    if(cord_local){
        GUI::drawOrigin(1);
    }

    GUI::setColor(0.5882,0.2941,0, 1,true);


    if(selecionado) {
       GUI::setColor(1,1,1, 1,true);
    }
    // Tronco

    // Face Frente
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0.5,0,0);
        glVertex3f(0.5,1,0);
        glVertex3f(0,1,0);
    glEnd();

    // Face Trás
    glBegin(GL_POLYGON);
        glNormal3f(0,0,-0.5);
        glVertex3f(0,0,-0.5);
        glVertex3f(0,1,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);
    glEnd();

    // Face Direita
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        glVertex3f(0.5,0,0);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,1,0);
    glEnd();

    // Face Esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,1,-0.5);
        glVertex3f(0,0,-0.5);
    glEnd();

    // Face Chão
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0,0);
    glEnd();

    // Fim Do Tronco

    GUI::setColor(0,0.7137,0.2235, 1,true);

    if(selecionado) {
       GUI::setColor(1,1,1, 1,true);
    }

    // Folhagem


    //Face Frente
    glBegin(GL_POLYGON);
        glNormal3f(0,1,1);
        glVertex3f(-0.25,1,0.25);
        glVertex3f(0.75,1,0.25);
        glVertex3f(0.25,2,-0.25);
    glEnd();

    //Face Trás
    glBegin(GL_POLYGON);
        glNormal3f(0,1,-1);
        glVertex3f(0.75,1,-0.75);
        glVertex3f(-0.25,1,-0.75);
        glVertex3f(0.25,2,-0.25);
    glEnd();

    //Face Direita
    glBegin(GL_POLYGON);
        glNormal3f(1,1,0);
        glVertex3f(0.75,1,0.25);
        glVertex3f(0.75,1,-0.75);
        glVertex3f(0.25,2,-0.25);
    glEnd();

    //Face Esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        glVertex3f(-0.25,1,-0.75);
        glVertex3f(-0.25,1,0.25);
        glVertex3f(0.25,2,-0.25);
    glEnd();

    //Face Baixo
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0.75,1,-0.75);
        glVertex3f(0.75,1,0.25);
        glVertex3f(-0.25,1,0.25);
        glVertex3f(-0.25,1,-0.75);
    glEnd();
}


void Arvore::desenhar_objeto(){
    glPushMatrix();
        Objeto::desenha_transformacoes(); // T.Rz.Ry.Rx.S. p
        criar();
    glPopMatrix();

}

