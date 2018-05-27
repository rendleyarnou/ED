#ifndef SFTEXT_H
#define SFTEXT_H
#include <SFML/Graphics.hpp>
#include <iostream>

class sfText : public sf::Text
{
public:
    sfText(sf::Vector2f pos, std::string texto, sf::Color color = sf::Color::White, int size = 16)
    {
        this->setFont(*this->get_default_font());
        this->setFillColor(color);
        this->setOutlineColor(color);
        this->setPosition(pos);
        this->setString(texto);
        this->setCharacterSize(size);
    }

private:


    static sf::Font * get_default_font(){
        const std::string _path = "../07_editor/libs/ed_font.ttf";
        static sf::Font font;
        static bool init = true;
        if(init){
            init = false;
            if(!font.loadFromFile(_path))
                std::cerr << "Font " << _path << " nao encontrada." << std::endl;
        }
        return &font;
    }
};
#endif // SFTEXT_H
