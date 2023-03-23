#include <iostream>
#include <vector>
#include "Objeto.h"
#include "Arvore.cpp"
#include "Mesa.cpp"
#include "Tenda.cpp"

using namespace std;

#include <gui.h>

Arvore *arvore_aux;
Mesa *mesa_aux;
Tenda *tenda_aux;

int index_selecionado = 0;
bool selecao_iniciada = false;

Vetor3D desl(0,0,0);//vetor de deslocamento tridimensional (x,y,z)
Vetor3D rot(0,0,0);
Model3DS carro = Model3DS("../3ds/cartest.3DS");


// Configuração inicial( colocar if posteriormente quando tiver arquivo )
Arvore *arvore = new Arvore(0,0,0,0,0,0,1,1,1,false,false);
Mesa *mesa = new Mesa(0,0,0,0,0,0,1,1,1,false,false);
Tenda *tenda = new Tenda(0,0,0,0,0,0,1,1,1,false,false);

vector<Objeto*> objetos;


//Sentido apontando para mim Anti-horário, para ângulos é a mesma coisa
//redefinir escalas, rotações e translações sempre de baixo para cima a partir do código

//void Quadrado_rosa()
//{
//    // Face Frente
//    glBegin(GL_POLYGON);
//        glNormal3f(0,0,1);
//        //Versão anti-horária
//        glVertex3f(0,0,0);
//        glVertex3f(1,0,0);
//        glVertex3f(1,1,0);
//        glVertex3f(0,1,0);

// //        Versão horária
// //        glVertex3f(0,0,0);
// //        glVertex3f(0,1,0);
// //        glVertex3f(1,1,0);
// //        glVertex3f(1,0,0);
//    glEnd();

//    // Face Atrás
//    glBegin(GL_POLYGON);
//        glNormal3f(0,0,-1);
//        glVertex3f(0,0,-1);
//        glVertex3f(0,1,-1);
//        glVertex3f(1,1,-1);
//        glVertex3f(1,0,-1);
//    glEnd();

//    // Face Esquerda
//    glBegin(GL_POLYGON);
//        glNormal3f(-1,0,0);
//        glVertex3f(0,0,0);
//        glVertex3f(0,1,0);
//        glVertex3f(0,1,-1);
//        glVertex3f(0,0,-1);
//    glEnd();

//    // Face Direita
//    glBegin(GL_POLYGON);
//        glNormal3f(1,0,0);
//        glVertex3f(1,0,0);
//        glVertex3f(1,0,-1);
//        glVertex3f(1,1,-1);
//        glVertex3f(1,1,0);
//    glEnd();

//    // Face Cima
//    glBegin(GL_POLYGON);
//        glNormal3f(0,1,0);
//        glVertex3f(0,1,0);
//        glVertex3f(1,1,0);
//        glVertex3f(1,1,-1);
//        glVertex3f(0,1,-1);
//    glEnd();

//    // Face Baixo
//    glBegin(GL_POLYGON);
//        glNormal3f(0,-1,0);
//        glVertex3f(1,0,0);
//        glVertex3f(0,0,0);
//        glVertex3f(0,0,-1);
//        glVertex3f(1,0,-1);
//    glEnd();
//}

//void Tenda() {

//}

void Escorregador(){
    GUI::setColor(1,1,0, 1,true);

    //face Direita Frente(Escada)
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(-0.25,0,-0.5);
        glVertex3f(-0.25,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();

    //face Direita Trás(Escada)
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(-0.5,0,-0.5);
        glVertex3f(-0.25,0,-0.5);
        glVertex3f(-0.25,0.5,-0.5);
        glVertex3f(-0.5,0.5,-0.5);
    glEnd();
}

//void Arvore(){

//}

//void Mesa() {


//}

void Aplicar_transformações() {
    // Aplicando transformações no objeto selecionado
    if(selecao_iniciada) {
        objetos[index_selecionado]->trans_x += glutGUI::dtx;
        objetos[index_selecionado]->trans_y += glutGUI::dty;
        objetos[index_selecionado]->trans_z += glutGUI::dtz;

        objetos[index_selecionado]->rot_x += glutGUI::dax;
        objetos[index_selecionado]->rot_y += glutGUI::day;
        objetos[index_selecionado]->rot_z += glutGUI::daz;

    }

}

void desenha() {
    GUI::displayInit();

    GUI::setLight(0,  3,5,4, true,false);//(tecla de apagar, x,y,z , desligar e ligar luz, (false = forte, true = atenuada))

    //GUI::drawOrigin(0.5);//(pontos em caxa eixo)
    GUI::drawOriginAL(5,1);// (tamanho de cada eixo, pontos em cada eixo)
    GUI::setColor(0.0118,0.7333,0.5216, 1,true);//(red,green,blue,opacidade,componente_de_reflexão)
    GUI::drawFloor(10,10,0.5,0.5);//(largura, comprimento, vertices largura, vertices comprimento)


    //GUI::setColor(0,1,0, 1,true);
    //GUI::drawBox(0+desl.x,0+desl.y,0+desl.z, 1+desl.x,1+desl.y,1+desl.z);//(x0,y0,z0, xf,yf,zf)

    // Configuração inicial( colocar if posteriormente quando tiver arquivo )
    glPushMatrix();
        glTranslatef(3,0,4);
        tenda->desenhar_objeto();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2,0,-3);
        arvore->desenhar_objeto();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2,0,3);
        mesa->desenhar_objeto();
    glPopMatrix();

    Aplicar_transformações();

    GUI::displayEnd();
}



void teclado( unsigned char tecla, int mouseX, int mouseY ) {
    GUI::keyInit(tecla,mouseX,mouseY);

    switch (tecla) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'w':
        desl.y += 0.01;
        break;
    case 's':
        desl.y -= 0.01;
        break;
    case 'a':
        /*
        arvore_aux = new Arvore(0,0,0,0,0,0,1,1,1,false,false);
        arvore_aux->desenhar_objeto();
        objetos.push_back(arvore_aux);
        */
        break;
    case 'd':
        desl.x += 0.01;
        break;
    case 'O':
        selecao_iniciada = !selecao_iniciada;
        objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
        break;
    case 'n':
        if(selecao_iniciada) {
            objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
            index_selecionado++;
            if(index_selecionado == objetos.size()){
                index_selecionado = 0;
            }
            objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
        }
        break;
    case 'b':
        if(selecao_iniciada) {
            objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
            index_selecionado--;
            if(index_selecionado == -1){
                index_selecionado = objetos.size() - 1;
            }
            objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
        }
        break;
    case 'v':
        if(selecao_iniciada) {
            objetos[index_selecionado]->cord_local = !objetos[index_selecionado]->cord_local;
        }
        break;
    default:
        break;
    }

}

int main()
{
    objetos.push_back(arvore);
    objetos.push_back(mesa);
    objetos.push_back(tenda);


    //GUI gui(800,600); // (largura, altura)
    GUI gui = GUI(800,600,desenha,teclado);
}

//inicializando OpenGL
//while(true) {
//    desenha();
//    interacaoUsuario();
//    //if () {
//    //    break;
//    //}
//}

//adicionar:
//-deslocar cubo com o teclado
//-deslocar cubo com o mouse
//-primitivas OpenGL (glBegin, glEnd)
//-glNormal, iluminação

//-leitor 3DS
//-usar as transformacoes matriciais do proprio OpenGL
//-push/popMatrix (podem ser usados um dentro do outro - nocao de pilha)

//-ordem das transformacoes
//  -translacao e rotacao
//  -testar escala!!!
//-interpretacao de uma composicao de transformacoes já definida
//      <----------- globais
//  -   T.Rz.Ry.Rx.S . v
//      -----------> locais
//  -direita->esquerda: Transfs globais
//  -esquerda->direita: Transfs locais
