#include <iostream>
#include <list>

using namespace std;

void mostrar_lista(list<int> lista){

    for(auto num : lista){
        cout << "O vencedor é o número: " << num << " " << endl;
    }
}

int main()
{

    int quantidade_guerreiros = 0, escolhido_espada = 0;

    cout << "Quantidade de guerreiros: " << endl;
    cin >> quantidade_guerreiros;
    cout << "Primeiro escolhido para matar: " << endl;
    cin >> escolhido_espada;

    list<int> lista_guerreiros;

    // laço para inserir o vetor de inteiros
    for(int i = 0; i < quantidade_guerreiros; i++){
        lista_guerreiros.push_back(i+1);
    }

    while(lista_guerreiros.front() != escolhido_espada){
        lista_guerreiros.push_back(lista_guerreiros.front());
        lista_guerreiros.pop_front();
    }

    while(lista_guerreiros.size() != 1){
        lista_guerreiros.push_back(lista_guerreiros.front());
        lista_guerreiros.pop_front();
        lista_guerreiros.pop_front();
    }

    mostrar_lista(lista_guerreiros);

    return 0;
}
