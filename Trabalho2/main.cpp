#include <iostream>

using namespace std;

#include <gui.h>
#include <vector>
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

int index_selecionado = 0;
bool selecao_iniciada = false;
size_t pontoSelecionado = 0;
//-------------------viewPorts------------------
bool viewports = false;
bool scissored = false;

//-------------------sombra-------------------
bool sombras_planos = false;
bool drawShadow = false;
bool tipo_luz = true;
float k = 0.0;

vector<Objeto*> objetos;


void atualizar_arquivo()
{
    ofstream arquivo; // dados programa -> arquivo
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
    ifstream arquivo; // dados arquivo -> programa
    arquivo.open("arquivo_save.txt");
    string linha;
    vector<float> dados_linha;
    char identificador_switch[10];
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            // stream a partir da string para facilitar a conversão
            std::stringstream ss(linha);

            double n;
            // Percorre o stream e adiciona cada número da linha ao vetor de float
            while (ss >> n) {
                dados_linha.push_back(n);
            }

            // Convertendo identificador de float para char
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
                case '6':
                    objetos.push_back(new Balanco(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
                        ,dados_linha[7],dados_linha[8],dados_linha[9],
                        (dados_linha[10] == 0) ? false : true , (dados_linha[11] == 0) ? false : true));
                    break;
                case '7':
                    objetos.push_back(new Lixo(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
                        ,dados_linha[7],dados_linha[8],dados_linha[9],
                        (dados_linha[10] == 0) ? false : true , (dados_linha[11] == 0) ? false : true));
                    break;
                case '8':
                    objetos.push_back(new Escorregador(dados_linha[0],dados_linha[1],dados_linha[2],dados_linha[3],dados_linha[4],dados_linha[5],dados_linha[6]
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
        // Configuração inicial do cenário
        objetos.push_back(new Arvore(1,-2.50,0,-3,0,0,0,1,1,1,false,false));
        objetos.push_back(new Arvore(1,-4,0,-3,0,0,0,1,1,1,false,false));
        objetos.push_back(new Mesa(2,0,0,0,0,0,0,1,1,1,false,false));
        objetos.push_back(new Mesa(2,-1,0,3,0,0,0,0.5,0.5,0.5,false,false));
        objetos.push_back(new Mesa(2,-2.90,0,3,0,0,0,0.5,0.5,0.5,false,false));
        objetos.push_back(new Mesa(2,-2,0,2,0,0,0,0.5,0.5,0.5,false,false));
        objetos.push_back(new Mesa(2,-2,0,4,0,0,0,0.5,0.5,0.5,false,false));
        objetos.push_back(new Tenda(3,3,0,3,0,0,0,2,1,2,false,false));
        objetos.push_back(new Banco(4,-3,0,-1,0,0,0,1,1,1,false,false));
        objetos.push_back(new Banco(4,-3,0,1,0,180,0,1,1,1,false,false));
        objetos.push_back(new Gangorra(5,3,0,-1,0,0,0,1,1,1,false,false));
        objetos.push_back(new Balanco(6,2,0,-3,0,0,0,1,1,1,false,false));
        objetos.push_back(new Lixo(7,-1,0,-1,0,0,0,1,1,1,false,false));
        objetos.push_back(new Escorregador(8,4,0,-3,0,0,0,1,1,1,false,false));
    }
}

void Aplicar_transformacoes() {
    // Aplicando transformações no objeto selecionado
    if ((pontoSelecionado != 0 and pontoSelecionado <= objetos.size())) {
        // Translações
        objetos[pontoSelecionado-1]->trans_x += 2 * glutGUI::dtx;
        objetos[pontoSelecionado-1]->trans_y += 2 * glutGUI::dty;
        objetos[pontoSelecionado-1]->trans_z += 2 * glutGUI::dtz;

        // Rotações
        objetos[pontoSelecionado-1]->rot_x += 2 * glutGUI::dax;
        objetos[pontoSelecionado-1]->rot_y += 2 * glutGUI::day;
        objetos[pontoSelecionado-1]->rot_z += 2 * glutGUI::daz;

        // Escalas
        objetos[pontoSelecionado-1]->esca_x += glutGUI::dsx;
        objetos[pontoSelecionado-1]->esca_y += glutGUI::dsy;
        objetos[pontoSelecionado-1]->esca_z += glutGUI::dsz;
    }
}

void displayInner() {
    //GUI::setLight(0,  3,5,4, true,false);//(tecla de apagar, x,y,z , desligar e ligar luz, (false = forte, true = atenuada))

    GUI::drawOrigin(1); // tamanho de cada eixo

    GUI::setColor(0.0118,0.7333,0.5216, 1,true);//(red,green,blue,opacidade,componente_de_reflexão)

    glPushMatrix();
        //-------------------sombra-------------------
        glTranslated(0.0,k,0.0); //glTranslated(0.0,k-0.001,0.0);
        GUI::drawFloor(10,10,0.1,0.1);//(largura, comprimento, vertices largura, vertices comprimento)

        //GUI::drawPlane(Vetor3D(2,2,3), k, 15, 15, 0.5, 0.5); //chama o drawFloor dentro //-0.001 definido dentro do drawFloor
        //GUI::drawPlane(Vetor3D(0,0,1), k, 15, 15, 0.5, 0.5);
        //GUI::drawPlane(Vetor3D(0,1,0), k, 15, 15, 0.5, 0.5);
        //-------------------sombra-------------------
    glPopMatrix();

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    //-------------------sombra-------------------
    //definindo a luz que sera usada para gerar a sombra
    float lightPos[4] = {1.5+glutGUI::lx,1.5+glutGUI::ly,1.5+glutGUI::lz,tipo_luz};
    //GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,pontual);
    GUI::setLight(0,3,5,4,true,false,false,false,tipo_luz);
    //desenhando os objetos projetados
    glPushMatrix();
        //matriz p multiplicar tudo por -1
            //float neg[16] = {
            //                   -1.0, 0.0, 0.0, 0.0,
            //                    0.0,-1.0, 0.0, 0.0,
            //                    0.0, 0.0,-1.0, 0.0,
            //                    0.0, 0.0, 0.0,-1.0
            //                };
            //glMultTransposeMatrixf( neg );
        //matriz de projecao para gerar sombra no plano y=k
            GLfloat sombra[4][4];
            GUI::shadowMatrixYk(sombra,lightPos,k);
            //GLfloat plano[4] = {0,1,0,-k};
            //GUI::shadowMatrix(sombra,plano,lightPos);
            glMultTransposeMatrixf( (GLfloat*)sombra );

        //matriz de projecao para gerar sombra no plano y=k
            //GLfloat sombra[4][4];
            //GUI::shadowMatrixYk(sombra,lightPos,k);
            //GLfloat plano[4] = {0,1,0,-k};
            //GLfloat plano[4] = {0,0,1,-k};
            //GLfloat plano[4] = {1,1,0,-k};
            //GLfloat plano[4] = {sqrt(2)/2.,sqrt(2)/2.,0,-k}; //      2/4 + 2/4 + 0 = 1
            //versao plano arbitrario passando coeficiente D do plano (não intuitivo p usuario - diferente de acordo com o tamanho do n)
            //GLfloat plano[4] = {2,2,3,-k}; //D = -k
            //GUI::shadowMatrix(sombra,plano,lightPos);
            //versao plano arbitrario passando dist minima do plano para a origem (mais intuitivo p usuario)
            //GLfloat distMin = k; //sinal indica se a distancia é no sentido da normal ou contrário
            //GUI::shadowMatrix(sombra, Vetor3D(2,2,3), distMin, lightPos);
            //glMultTransposeMatrixf( (GLfloat*)sombra );



        glDisable(GL_LIGHTING);
        glColor3d(0.0,0.0,0.0);
        if (drawShadow) {
            bool aux = glutGUI::draw_eixos;
            glutGUI::draw_eixos = false;
                glPushMatrix();
                    objetos[index_selecionado]->desenha();
                glPopMatrix();
            glutGUI::draw_eixos = aux;
        }
        glEnable(GL_LIGHTING);

        //glDisable(GL_LIGHTING);
        //glColor3d(0.0,0.0,0.0);
        //if (drawShadow) desenhaObjetosComSombra();
        //glEnable(GL_LIGHTING);
    glPopMatrix();
    //-------------------sombra-------------------
}

void sombra_plano_qualquer( GLfloat plano[4], float lightPos[4] ) {
    bool aux = glutGUI::draw_eixos;
    glutGUI::draw_eixos = false;

    for (size_t i = 0; i < objetos.size(); i++) {
        glDisable(GL_LIGHTING);
        glColor4d(0.0,0.0,0.0, 0.5);

        GLfloat sombra[4][4];

        glPushMatrix();
            GUI::shadowMatrix(sombra,plano,lightPos);
            glMultTransposeMatrixf( (GLfloat*)sombra );
                objetos[index_selecionado]->desenha();
            glEnable(GL_LIGHTING);
        glPopMatrix();
    }
}

void mostrarSombrasNosPlanos() {
    float lightPos[4] = {glutGUI::lx,glutGUI::ly,glutGUI::lz,tipo_luz ? 1.0f : 0.0f};

    GUI::setLight(0,lightPos[0],lightPos[1],lightPos[2],true,false,false,false,tipo_luz);
    GLfloat plano_chao[4] = {0,1,0, -0.001};
    sombra_plano_qualquer(plano_chao, lightPos);

    // lateral
    GUI::setColor(1, 0.98, 0.98);
    glPushMatrix();
        GUI::drawBox(-5,0,-5, -4.77,5,0);
    glPopMatrix();
    GLfloat plano_lateral[4] = {0.63,0,0, 3.00-0.001};
    sombra_plano_qualquer(plano_lateral, lightPos);

    // frente
    GUI::setColor(1, 0.98, 0.98);
    glPushMatrix();
        GUI::drawBox(-4.77,0,-5, 0,5,-4.77);
    glPopMatrix();
    GLfloat plano_frente[4] = {0,0,0.63, 3.00-0.001};
    sombra_plano_qualquer(plano_frente, lightPos);

    // inclinado
    GUI::setColor(1, 0.98, 0.98);
    glPushMatrix();
        glTranslatef(-4.04,0,-2.5);
        glRotatef(-45, 0,0,1);
        GUI::drawQuad(2,5);
    glPopMatrix();
    GLfloat plano_inclinado[4] = {0.63,0.63,0, 2.54-0.001};
    sombra_plano_qualquer(plano_inclinado, lightPos);
}

void desenha_viewports_gerais() {
    GUI::displayInit();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(glutGUI::cam->e.x,glutGUI::cam->e.y,glutGUI::cam->e.z,glutGUI::cam->c.x,glutGUI::cam->c.y,glutGUI::cam->c.z,glutGUI::cam->u.x,glutGUI::cam->u.y,glutGUI::cam->u.z);
    displayInner();

    glLoadIdentity();
    glViewport(0, glutGUI::height/2, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(0,10,0, 0,0,0, 0,0,1);
    displayInner();

    glLoadIdentity();
    glViewport(glutGUI::width/2, 0, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(0,1,-10, 0,1,0, 0,1,0);
    displayInner();

    glLoadIdentity();
    glViewport(glutGUI::width/2, glutGUI::height/2, glutGUI::width/2, glutGUI::height/2);
    gluLookAt(10,1,0, 0,1,0, 0,1,0);
    displayInner();
}

void desenha() {
    GUI::displayInit();

    if(!viewports){
       displayInner();
    }else {
       desenha_viewports_gerais();
    }

    if (sombras_planos) {
        mostrarSombrasNosPlanos();
    }

    Aplicar_transformacoes();

    GUI::displayEnd();

    atualizar_arquivo();
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
        objetos.push_back(new Balanco(5,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '7':
        objetos.push_back(new Lixo(5,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '8':
        objetos.push_back(new Escorregador(5,0,0,0,0,0,0,1,1,1,false,false));
        break;
    case '!':
        // Perpectiva: 1 ponto de fuga
        glutGUI::cam->e.x = 1.5;
        glutGUI::cam->e.y = -0.25;
        glutGUI::cam->e.z = 0;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 1;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '@':
        // Perpectiva: 2 pontos de fuga
        glutGUI::cam->e.x = 1.25;
        glutGUI::cam->e.y = 0.5;
        glutGUI::cam->e.z = -1.25;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 1;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '#':
        // Perpectiva: 3 pontos de fuga
        glutGUI::cam->e.x = 1.5;
        glutGUI::cam->e.y = -0.25;
        glutGUI::cam->e.z = 1.5;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 1;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '$':
        // Ortográfica(vista): Frontal
        glutGUI::cam->e.x = 0;
        glutGUI::cam->e.y = 0.5;
        glutGUI::cam->e.z = 2;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0.5;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '%':
        // Ortográfica(vista): Lateral
        glutGUI::cam->e.x = 2;
        glutGUI::cam->e.y = 0.5;
        glutGUI::cam->e.z = 0;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0.5;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '&':
        // Ortográfica(vista): Planta
        glutGUI::cam->e.x = 0;
        glutGUI::cam->e.y = 4;
        glutGUI::cam->e.z = 0;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 0;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 0;
        glutGUI::cam->u.z = -1;
        break;
    case '*':
        // Ortográfica(axonométrica): Isométrica
        glutGUI::cam->e.x = 3;
        glutGUI::cam->e.y = 2;
        glutGUI::cam->e.z = 3;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 1;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case '(':
        // Ortográfica(axonométrica): Dimétrica
        glutGUI::cam->e.x = 3;
        glutGUI::cam->e.y = 1;
        glutGUI::cam->e.z = 3;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 1;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case ')':
        // Ortográfica(axonométrica): Trimétrica
        glutGUI::cam->e.x = 3;
        glutGUI::cam->e.y = 1;
        glutGUI::cam->e.z = 2.5;
        glutGUI::cam->c.x = 0;
        glutGUI::cam->c.y = 1;
        glutGUI::cam->c.z = 0;
        glutGUI::cam->u.x = 0;
        glutGUI::cam->u.y = 1;
        glutGUI::cam->u.z = 0;
        break;
    case 'd':
        if(selecao_iniciada) {
            objetos.erase(objetos.begin() + index_selecionado); // apaga o objeto do index atual
            index_selecionado--; // reduz para o index anterior no vetor

            // caso o primeiro objeto seja deletado o index vai para o último ( ideia ciclica do vetor )
            if(index_selecionado == -1){
                index_selecionado = objetos.size() - 1;
            }

            // caso o vetor esteja vazio a seleção termina e o index volta para o valor default de 0
            if(objetos.size() == 0) {
                index_selecionado = 0;
                selecao_iniciada = false;
            }

            if(selecao_iniciada) { // verifica se o vector ainda possui valores, se possuir seta o selecionado do atual objeto do vetor
                objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
            }
        }
        break;
    case 'D':
        if(selecao_iniciada) {
            // caso o último objeto seja o atual selecionado então o index é reduzido para o penúltimo
            if(index_selecionado == objetos.size() -1){
                index_selecionado--;
                objetos[index_selecionado]->selecionado = !objetos[index_selecionado]->selecionado;
            }

            // apagando último objeto do vetor
            objetos.erase(objetos.begin() + (objetos.size() - 1));

            // caso o vetor esteja vazio a seleção termina e o index volta para o valor default de 0
            if(objetos.size() == 0) {
                index_selecionado = 0;
                selecao_iniciada = false;
            }

        }
        break;
    case 'v':
        if(selecao_iniciada) {
            // desenhar coordenadas locais no objeto selecionado
            objetos[index_selecionado]->cord_local = !objetos[index_selecionado]->cord_local;
        }
        break;
    case 's':
        if(selecao_iniciada) {
            drawShadow = !drawShadow;
        }
        break;
    case '/':
        // mostra sombras em planos arbitrários(parede, chão, plano inclinado)
        sombras_planos = !sombras_planos;
        break;
    case '-':
        // Troca entre luz pontual próxima e luz distante
        tipo_luz = !tipo_luz;
        break;
    case 'b':
        viewports = !viewports;
        break;
    case 'n':
        glutGUI::perspective = !glutGUI::perspective;
        break;
    default:
        break;
    }
}

void desenhaPontosDeControle()
{
    for (size_t i=0; i < objetos.size(); i++) {
        glPushName(i+1);
            objetos[i]->desenha();
        glPopName();
    }
}

int picking( GLint cursorX, GLint cursorY, int w, int h ) {
    int BUFSIZE = 512;
    GLuint selectBuf[512];
    GUI::pickingInit(cursorX,cursorY,w,h,selectBuf,BUFSIZE);
    GUI::displayInit();
    objetos[index_selecionado]->selecionado = false;
    desenhaPontosDeControle();
    return GUI::pickingClosestName(selectBuf,BUFSIZE);
}

void mouse(int button, int state, int x, int y) {
    GUI::mouseButtonInit(button,state,x,y);

    // if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            //picking
            int pick = picking( x, y, 5, 5 );
            if (pick != 0) {
                selecao_iniciada = true;
                pontoSelecionado = pick;
                objetos[pontoSelecionado-1]->selecionado = true;
                index_selecionado = pontoSelecionado-1;
                glutGUI::lbpressed = false;
            }else {
                selecao_iniciada = false;
            }
        }
    }
}

int main()
{
    ler_arquivo();
    //GUI gui(800,600); // (largura, altura)
    GUI gui = GUI(800,600,desenha,teclado, mouse);
}
