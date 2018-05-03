#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
    player.setFillColor(sf::Color::Red);
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
            case sf::Event::Resized:
                std::cout<<evnt.size.width<<' '<<evnt.size.height<<'\n';
            break;
            case sf::Event::TextEntered:
                if(evnt.text.unicode<128)
                std::cout<<(char)evnt.text.unicode;
            break;

            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-0.1f,0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(0.1f,0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0.0f,-0.1f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0.0f,0.1f);
        }
        window.draw(player);
        window.display();
        window.clear();
    }
    return 0;
}
