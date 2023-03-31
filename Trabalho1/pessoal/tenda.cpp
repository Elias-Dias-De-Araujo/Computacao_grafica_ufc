#include "tenda.h"

Tenda::Tenda(int ident, float t_x, float t_y, float t_z,
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

void Tenda::criar(){
    if(cord_local){
        GUI::drawOrigin(1);
    }

    GUI::setColor(1,0.4118,0.3804, 1,true);


    if(selecionado) {
       GUI::setColor(1,1,1, 1,true);
    }

    //Linha da base ao topo
    GUI::drawBox(-0.01,0,-0.01, 0.01,1,0.01);
    glBegin(GL_LINES);
        glNormal3f(1,1,1);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
    glEnd();

    // Base do teto
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,1,0.5);
        glVertex3f(-0.5,1,0.5);
        glVertex3f(-0.5,1,-0.5);
    glEnd();

    // Base do chão
    glBegin(GL_POLYGON);
        glNormal3f(0,1,0);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();

    // Base do chão(inferior)
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,0,0.5);
        glVertex3f(-0.5,0,0.5);
    glEnd();

    //Triangulo Frente
    glBegin(GL_POLYGON);
        glNormal3f(0,1,1);
        glVertex3f(-0.5,1,0.5);
        glVertex3f(0.5,1,0.5);
        glVertex3f(0,1.5,0);
    glEnd();

    //Triangulo Trás
    glBegin(GL_POLYGON);
        glNormal3f(0,1,-1);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(0,1.5,0);
    glEnd();

    //Triangulo Direita
    glBegin(GL_POLYGON);
        glNormal3f(1,1,0);
        glVertex3f(0.5,1,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0,1.5,0);
    glEnd();

    //Triangulo Esquerda
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,1,0.5);
        glVertex3f(0,1.5,0);
    glEnd();

}

void Tenda::desenha(){
    glPushMatrix();
        Objeto::desenha(); // T.Rz.Ry.Rx.S. p
        criar();
    glPopMatrix();

}

