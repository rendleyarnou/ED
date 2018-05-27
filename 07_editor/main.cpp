#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "libs/sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }
    //construtor de cópia
    Ambiente(const Ambiente& other):
        texto(other.texto)
    {
        this->cursor = this->texto.begin();
        for(auto it = other.texto.begin(); it != other.cursor; it++)
            this->cursor++;
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "|";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "|";
        return ss.str();
    }
};

int main()
{
    Ambiente amb;
    list<Ambiente> ambientes;
    amb.texto.push_back('a');
    amb.texto.push_back('m');
    amb.texto.push_back('o');
    amb.texto.push_back('r');
    amb.cursor = amb.texto.end();

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && (event.key.code == sf::Keyboard::Z)){// CTRL + Z
                        cout << "control z" << endl;
                        ambientes.reverse_iterator;
                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){// CTRL + R
                        cout << "control r" << endl;
                }
                else if((event.key.code >= sf::Keyboard::A) && (event.key.code <= sf::Keyboard::Z)){// DIGITAR
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    if(event.key.shift)
                        tecla += -'a' + 'A';
                    amb.texto.insert(amb.cursor, tecla);
                    ambientes.push_back(amb);
                }
                else if((event.key.code == sf::Keyboard::Return)){ // ENTER
                    amb.texto.insert(amb.cursor, '\n');
                }
                else if((event.key.code == sf::Keyboard::Space)){// ESPAÇO
                    amb.texto.insert(amb.cursor, ' ');
                }
                else if(event.key.code == sf::Keyboard::BackSpace){// BACKSPACE
                    if(amb.texto.size() > 0){
                        if(amb.cursor != amb.texto.begin()){
                            amb.texto.erase(amb.cursor++,amb.cursor--);
                        }
                    }
                }
                else if(event.key.code == sf::Keyboard::Delete){// DELETE
                    if(amb.cursor != amb.texto.end()){
                        amb.cursor++;
                        amb.texto.erase(amb.cursor++,amb.cursor--);
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){// MOVER PARA A ESQUERDA
                    amb.cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){// MOVER PARA A DIREITA
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}
