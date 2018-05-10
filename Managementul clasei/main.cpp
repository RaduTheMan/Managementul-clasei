#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "Managementul clasei", sf::Style::Close);
    sf::Texture fundal_t;
    sf::Sprite fundal_s;
    sf::Texture titlu_t;
    sf::Sprite titlu_s;
    sf::Image icon;
    icon.loadFromFile("icon.png");
    titlu_t.loadFromFile("titlu.png");
    titlu_s.setTexture(titlu_t);
    titlu_s.setPosition(window.getSize().x/2-titlu_s.getLocalBounds().width/2,100);
    fundal_t.loadFromFile("fundal.jpg");
    fundal_s.setTexture(fundal_t);
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
    while(window.isOpen())
    {
        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case sf::Event::Closed:
                window.close();
            break;
            }
        }
        window.draw(fundal_s);
        window.draw(titlu_s);
        window.display();
        window.clear();
    }
    return 0;
}
