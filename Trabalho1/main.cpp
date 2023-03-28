#include <iostream>

using namespace std;

#include <gui.h>
#include <vector>

//#include <objeto.h>
#include <fstream>
#include <vector>
#include <gui.h>
#include <string>
#include <sstream>
#include "objeto.h"
#include "arvore.h"
#include "mesa.h"
#include "tenda.h"
#include "banco.h"
#include "gangorra.h"
#include "balanco.h"
#include "escorregador.h"
#include "lixo.h"

//Model3DS model3ds("../3ds/cartest.3DS");

int index_selecionado = 0;
bool selecao_iniciada = false;

Vetor3D desl(0,0,0);//vetor de deslocamento tridimensional (x,y,z)
Vetor3D rot(0,0,0);

vector<Objeto*> objetos;


//Sentido apontando para mim Anti-horário, para ângulos é a mesma coisa
//redefinir escalas, rotações e translações sempre de baixo para cima a partir do código

void atualizar_arquivo()
{
    ofstream arquivo;
    arquivo.open("arquivo_save.txt");
    for (int i = 0; i < objetos.size(); ++i) {
        arquivo << objetos[i]->identifier << " " << objetos[i]->trans_x << " " << objetos[i]->trans_y << " " << objetos[i]->trans_z << " " <<
                   objetos[i]->rot_x << " " << objetos[i]->rot_y << " " << objetos[i]->rot_z << " " <<
                   objetos[i]->esca_x << " " << objetos[i]->esca_y << " " << objetos[i]->esca_z << " " <<
                   0 << " " << 0 <<"\n";
    }
    arquivo.close();
}

void ler_arquivo()
{
    ifstream arquivo;
    arquivo.open("arquivo_save.txt");
    string linha;
    vector<float> dados_linha;
    char identificador_switch[10];
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            // stream a partir da string para facilitar a conversão
            std::stringstream ss(linha);

            double n;
            // Percorre o stream e adiciona cada número ao vetor
            while (ss >> n) {
                dados_linha.push_back(n);
            }


            // Convertendo identificador float para char
            sprintf(identificador_switch, "%f", dados_linha[0]);
            switch(identificador_switch[0]) {
                case '1':
                    objetos.push_back(new Arvore(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
                            ,dados_linha[7],dados_linha[8],dados_linha[9],
                            (dados_linha[10] == 0) ? false : true , (dados_linha[11] == 0) ? false : true));
                    break;
                case '2':
                objetos.push_back(new Mesa(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
                        ,dados_linha[7],dados_linha[8],dados_linha[9],
                        (dados_linha[10] == 0) ? false : true , (dados_linha[11] == 0) ? false : true));
                    break;
                case '3':
                objetos.push_back(new Tenda(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
                        ,dados_linha[7],dados_linha[8],dados_linha[9],
                        (dados_linha[10] == 0) ? false : true , (dados_linha[11] == 0) ? false : true));
                    break;
                case '4':
                objetos.push_back(new Banco(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
                    ,dados_linha[7],dados_linha[8],dados_linha[9],
                    (dados_linha[10] == 0) ? false : true , (dados_linha[11] == 0) ? false : true));
                break;
                case '5':
                objetos.push_back(new Gangorra(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
                    ,dados_linha[7],dados_linha[8],dados_linha[9],
                    (dados_linha[10] == 0) ? false : true , (dados_linha[11] == 0) ? false : true));
                break;
                default:
                    break;
            }
            dados_linha.clear();
        }
        arquivo.close();
    }else {

        objetos.push_back(new Arvore(1,-2.50,0,-3,0,0,0,1,1,1,false,false));
        objetos.push_back(new Arvore(1,-4,0,-3,0,0,0,1,1,1,false,false));

        // mesa centro
        objetos.push_back(new Mesa(2,-2,0,3,0,0,0,1,1,1,false,false));
        // mesa direita
        objetos.push_back(new Mesa(2,-1,0,3,0,0,0,0.5,0.5,0.5,false,false));
        // mesa esquerda
        objetos.push_back(new Mesa(2,-2.90,0,3,0,0,0,0.5,0.5,0.5,false,false));
        // mesa frente
        objetos.push_back(new Mesa(2,-2,0,2,0,0,0,0.5,0.5,0.5,false,false));
        // mesa trás
        objetos.push_back(new Mesa(2,-2,0,4,0,0,0,0.5,0.5,0.5,false,false));

        // Tenda quadrante inferior direito
        objetos.push_back(new Tenda(3,3,0,3,0,0,0,2,1,2,false,false));

        // Bancos
        objetos.push_back(new Banco(4,-3,0,-1,0,0,0,1,1,1,false,false));
        objetos.push_back(new Banco(4,-3,0,1,0,180,0,1,1,1,false,false));

        objetos.push_back(new Gangorra(5,3,0,-1,0,0,0,1,1,1,false,false));
        objetos.push_back(new Balanco(6,2,0,-4,0,0,0,1,1,1,false,false));
    }
}

void Aplicar_transformações() {
    // Aplicando transformações no objeto selecionado
    if(selecao_iniciada) {
        // Translações
        objetos[index_selecionado]->trans_x += glutGUI::dtx;
        objetos[index_selecionado]->trans_y += glutGUI::dty;
        objetos[index_selecionado]->trans_z += glutGUI::dtz;

        // Rotações
        objetos[index_selecionado]->rot_x += glutGUI::dax;
        objetos[index_selecionado]->rot_y += glutGUI::day;
        objetos[index_selecionado]->rot_z += glutGUI::daz;

        // Escalas
        objetos[index_selecionado]->esca_x += glutGUI::dsx;
        objetos[index_selecionado]->esca_y += glutGUI::dsy;
        objetos[index_selecionado]->esca_z += glutGUI::dsz;
    }
}

void displayInner() {
    GUI::setLight(0,  3,5,4, true,false);//(tecla de apagar, x,y,z , desligar e ligar luz, (false = forte, true = atenuada))

    //GUI::drawOrigin(1);//(pontos em caxa eixo)
    GUI::drawOriginAL(5,1);// (tamanho de cada eixo, pontos em cada eixo)
    GUI::setColor(0.0118,0.7333,0.5216, 1,true);//(red,green,blue,opacidade,componente_de_reflexão)
    GUI::drawFloor(10,10,0.5,0.5);//(largura, comprimento, vertices largura, vertices comprimento)


    //GUI::setColor(0,1,0, 1,true);
    //GUI::drawBox(0+desl.x,0+desl.y,0+desl.z, 1+desl.x,1+desl.y,1+desl.z);//(x0,y0,z0, xf,yf,zf)

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }
}

void desenha() {
    GUI::displayInit();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(glutGUI::cam->e.x,glutGUI::cam->e.y,glutGUI::cam->e.z, glutGUI::cam->c.x,glutGUI::cam->c.y,glutGUI::cam->c.z, glutGUI::cam->u.x,glutGUI::cam->u.y,glutGUI::cam->u.z);

    displayInner();

    Aplicar_transformações();

    GUI::displayEnd();

    //atualizar_arquivo();
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
    case '1':
        objetos.push_back(new Arvore(1,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '2':
        objetos.push_back(new Mesa(2,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '3':
        objetos.push_back(new Tenda(3,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '4':
        objetos.push_back(new Banco(4,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '5':
        objetos.push_back(new Gangorra(5,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '6':
        glutGUI::cam->e.x = 0;
        glutGUI::cam->e.y = 15;
        glutGUI::cam->e.z = 0;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 1;
        glutGUI::cam->u.y = 0;
        glutGUI::cam->u.z = 0;
        break;
    case '7':
        glutGUI::cam->e.x = -10;
        glutGUI::cam->e.y = 2;
        glutGUI::cam->e.z = 10;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '8':
        glutGUI::cam->e.x = 10;
        glutGUI::cam->e.y = 2;
        glutGUI::cam->e.z = 10;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '9':
        glutGUI::cam->e.x = 10;
        glutGUI::cam->e.y = 2;
        glutGUI::cam->e.z = -10;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '-':
        glutGUI::cam->e.x = -10;
        glutGUI::cam->e.y = 2;
        glutGUI::cam->e.z = -10;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '=':
        glutGUI::cam->e.x = 0;
        glutGUI::cam->e.y = 1;
        glutGUI::cam->e.z = -10;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 1;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case 'd':
        if(selecao_iniciada) {
            objetos.erase(objetos.begin() + index_selecionado);
            index_selecionado--;
            if(index_selecionado == -1){
                index_selecionado = objetos.size() - 1;
            }
            if(objetos.size() == 0) {
                index_selecionado = 0;
                selecao_iniciada = false;
            }

            if(selecao_iniciada) { // verifica se o vector ainda possui valores, se possuir seta o selecionado do outro objeto do vector
                objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
            }
        }
        break;
    case 'D':
        if(selecao_iniciada) {
            if(index_selecionado == objetos.size() -1){
                index_selecionado--;
                objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
            }

            objetos.erase(objetos.begin() + (objetos.size() - 1));

            if(objetos.size() == 0) {
                index_selecionado = 0;
                selecao_iniciada = false;
            }

        }

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
    ler_arquivo();
    //GUI gui(800,600); // (largura, altura)
    GUI gui = GUI(800,600,desenha,teclado);
}
