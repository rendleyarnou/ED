#include <iostream>
#include <cstdlib>

using namespace std;

struct vetor{
    int * _data;
    int _capacidade;
    int _size;

    vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
        this->_data = new int[capacidade];
    }

    //INSERE UM VALOR NO VETOR E ACRESCENTA MAIS UM BLOCO DE MEMORIA NO VETOR
    void push_back(int value){
        //se cair nessa condição e vc ainda quiser inserir, vc dever reservar uma nova
        //capacidade
        if(this->_size == this->_capacidade)
            return;
        this->_data[this->_size] = value;
        if(this->_capacidade == this->_size + 1)
            this->_size += 1;
    }

    //REMOVE O ULTIMO BLOCO DE MEMORIA DO VETOR
    void pop_back(){
        if(this->_size == 0){
            return;
        }else{
            this->_size -= 1;
        }
    }

    //BUSCA O INDICE INDICADO NO VETOR
    int& at(int indice){
        return this->_data[indice];
    }

    //MOSTRA O PRIMEIRO INDICE DO VETOR
    int& front(){
        return this->_data[0];
    }

    //MOSTRA O ULTIMO INDICE DO VETOR
    int& back(){
        return this->_data[this->_size - 1];
    }

    //MOSTRA O VALOR DO PRIMEIRO INDICE DO VETOR
    int * begin(){
        return &this->_data[0];
    }

    //MOSTRA O VALOR DO ULTIMO INDICE DO VETOR
    int * end(){
        return &this->_data[this->_size - 1];
    }

    //MOSTRA O TAMANHO DO VETOR
    int size(){
        return this->_size;
    }

    //MOSTRA A CAPACIDADE DO VETOR
    int capacity(){
        return this->_capacidade;
    }

    //RESERVA UMA DETERMINADA CAPACIDADE DO VETOR
    void reserve(int new_capacity){
        if(new_capacity < this->capacity())
            return;
        this->_capacidade += new_capacity;
        this->_data = new int[this->_capacidade];
    }

};

int main(){

    vetor vetin(5);

    cout << "Size: " << vetin.size() << endl;
    cout << "Capacidade: " << vetin.capacity() << endl;

    vetin.reserve(5);

    cout << "Size: "<< vetin.size() << endl;
    cout << "Capacidade: " << vetin.capacity() << endl;


    return 0;
}

