#include "arvore.h"

Arvore::Arvore(int ident, float t_x, float t_y, float t_z,
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


void Arvore::desenha(){
    glPushMatrix();
        Objeto::desenha(); // T.Rz.Ry.Rx.S. p
        glTranslatef(2,1,0);
        glRotatef(90,1,0,0);
        glRotatef(-90,0,0,1);
        glScalef(1,0.5,1);
        glScalef(1,1,0.5);
        glRotatef(90,0,1,0);
        glRotatef(-45,0,0,1);
        glTranslatef(-1,-2,0);
        criar();
    glPopMatrix();

}
