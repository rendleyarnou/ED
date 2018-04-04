#include <iostream>
#include <vector>

using namespace std;

const int linhas = 20;
const int colunas = 60;

struct Par{
    int l, c;
};

vector<Par> adjacentes(int l, int c){

    vector<Par> adj;

    adj.push_back(Par{l, c - 1});
    adj.push_back(Par{l, c + 1});
    adj.push_back(Par{l - 1, c});
    adj.push_back(Par{l + 1, c});

   return adj;
}

void mostrar(char mat[linhas][colunas]){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void esperar(){
    char enter;
    cin >> std::noskipws >> enter;
}

void quebrar(){

    for(int i = 0; i < 20; i++){
        cout << endl;
    }

}

int queimar(char mat[linhas][colunas], int l, int c, int nivel){
    int troncos = 0;
    if(l < 0 || l >= linhas){
        return 0;
    }
    if(c < 0 || c >= colunas){
        return 0;
    }
    if(mat[l][c] == '#'){
        troncos = 1;
        mat[l][c] = '0' + nivel%10;
        quebrar();
        mostrar(mat);
        esperar();
        for(auto par : adjacentes(l, c)){
            troncos += queimar(mat, par.l, par.c, nivel + 1);
        }
        mat[l][c] = '.';
    }
    return troncos;
}

int main(){

    char mat[linhas][colunas];
    int nivel = 0;

    //laço para preencher a matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j< colunas; j++){
            mat[i][j] = ' ';
        }
    }

    int narvores = linhas * colunas * 1.5;

    for(int a = 0; a < narvores; a++){
        mat[rand() % linhas][rand() % colunas] = '#';
    }

    mostrar(mat);
    quebrar();
    //contador de arvores queimadas
    int cont = queimar(mat, 0, 0, nivel);
    cout << "Árvores queimadas: " << cont << endl;

    return 0;
}
