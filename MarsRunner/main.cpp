#include <SFML/Graphics.hpp>

#include "Code/Game engine/Object systems/GameObject.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
   
    std::string thing = "../Assets/Test/testplaatje.png";
    GameObject object{ thing, sf::Vector2f{0,0}, sf::Vector2f{0.1,0.1}, 5 };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        object.draw(window);
        window.display();
    }

    return 0;
}