#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm> //random_shuffle

using namespace std;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char CAMINHO = 'b';

void mostrar_matriz(matchar& mat, vector<Par> pilha, Par inicio, Par fim){
    mat_draw(mat);
    for(Par par : pilha){
        mat_focus(par, 'c');//por onde o par esta passando
    }if(pilha.size() > 0){
        mat_focus(pilha.back(), 'k');//posição onde o par esta atualmente
    }
    mat_focus(inicio, 'g');//ponto de inicio
    mat_focus(fim, 'r');//ponto final escolhido
}


vector<Par> pegar_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));

    return vizinhos;
}

vector<Par> pegar_all_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));//baixo
    vizinhos.push_back(Par(par.l - 1, par.c));//cima
    vizinhos.push_back(Par(par.l, par.c + 1));//direita
    vizinhos.push_back(Par(par.l, par.c - 1));//esquerda
    vizinhos.push_back(Par(par.l, par.c));
    vizinhos.push_back(Par(par.l, par.c));
    vizinhos.push_back(Par(par.l, par.c));
    vizinhos.push_back(Par(par.l, par.c));


    return vizinhos;
}

int contar_vizinhos_abertos(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : pegar_vizinhos(par))
        if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
            cont++;
    return cont;
}

vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

void furar(matchar &mat, Par par){

    vector<Par> vetor;

    vetor.push_back(par);
    mat.get(par) = ABERTO;

    while(vetor.size() != 0){
        vector<Par> viz_para_furar;
        Par ultimo = vetor.back();
        for(auto vizinho : shuffle(pegar_vizinhos(ultimo))){
            if(contar_vizinhos_abertos(mat, vizinho) == 1 && mat.equals(vizinho, PAREDE)){
                viz_para_furar.push_back(vizinho);
            }
        }
        if(viz_para_furar.size() == 0){
            vetor.pop_back();
        }else{
            Par da_vez = viz_para_furar[rand() % viz_para_furar.size()];
            vetor.push_back(da_vez);
            mat.get(da_vez) = ABERTO;
            mat_draw(mat);
            ed_show();
        }
    }
}

bool encontrar_caminho(matchar &mat, Par inicio, Par final){
    vector<Par> pilha;
    pilha.push_back(inicio);
    mat.get(inicio) = CAMINHO;

    while(pilha.size() != 0){
        Par topo = pilha.back();
        if(topo == final){
            mostrar_matriz(mat, pilha, inicio, final);
            ed_show();
            return true;
        }
        vector<Par> viz_abertos;
        mostrar_matriz(mat, pilha, inicio, final);
        for(Par par : pegar_vizinhos(topo)){
            if(mat.get(par) == ABERTO){
                viz_abertos.push_back(par);
                mat_focus(par, 'r');
            }
        }
        ed_show();
        if(viz_abertos.size() == 0){
            pilha.pop_back();
            mostrar_matriz(mat, pilha, inicio, final);
            ed_show();
        }else{
            Par escolhido = viz_abertos[rand() % viz_abertos.size()];
            mat.get(escolhido) = CAMINHO;
            pilha.push_back(escolhido);
            mostrar_matriz(mat, pilha, inicio, final);
            ed_show();
        }
    }
    mostrar_matriz(mat, pilha, inicio, final);
    ed_show();
    return false;
}

#include <cstdlib>
#include <ctime>
int main(){

    srand(time(NULL));
    matchar mat(30, 45, PAREDE);
    furar(mat, Par(1, 1));//chama a função furar
    mat_draw(mat);
    ed_show();
    Par inicio = mat_get_click(mat, "digite o local de inicio");
    Par final = mat_get_click(mat, "digite o local de fim");
    mat_draw(mat);
    ed_show();

    encontrar_caminho(mat, inicio, final);
    ed_lock();//impede que termine abruptamente
    return 0;
}
