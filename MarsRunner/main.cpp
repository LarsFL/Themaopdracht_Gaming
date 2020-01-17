#include <SFML/Graphics.hpp>
#include <vector>

#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"
#include "Code/Game engine/Object systems/Player.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
   
    std::string thing = "../Assets/Test/testplaatje.png";

    GameObject ground { thing, sf::Vector2f{250,250}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground1 { thing, sf::Vector2f{0,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground2 { thing, sf::Vector2f{82,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground3{ thing, sf::Vector2f{164,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground4{ thing, sf::Vector2f{246,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground5{ thing, sf::Vector2f{328,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground6{ thing, sf::Vector2f{410,400}, sf::Vector2f{0.1,0.1}, 5, false };

    std::vector<GameObject*> groundObjects = { &ground, &ground1, &ground2 ,&ground3, &ground4, &ground5, &ground6 };

    Player player{ thing, sf::Vector2f{0,250}, sf::Vector2f{0.1,0.1}, 5, false, window, groundObjects };
    player.setVelocity(sf::Vector2f{ 0.0, 1.1 });

    while (window.isOpen()) {

        window.clear();

        player.update();

        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}