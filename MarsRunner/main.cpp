#include <SFML/Graphics.hpp>

#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
   
    std::string thing = "../Assets/Test/Astronaut_idle.png";
    GameObject object{ thing, sf::Vector2f{0,0}, sf::Vector2f{2,2}, 5 };


    action actions[] = {
        action(sf::Keyboard::Up,    [&]() { std::cout << "Up\n"; }),
        action(sf::Keyboard::Left,  [&]() { std::cout << "Left\n"; }),
        action(sf::Keyboard::Down,  [&]() { std::cout << "Down\n"; }),
        action(sf::Keyboard::Right, [&]() { std::cout << "Right\n"; }),

        action(sf::Keyboard::W,     [&]() { std::cout << "W\n"; }),
        action(sf::Keyboard::A,     [&]() { std::cout << "A\n"; }),
        action(sf::Keyboard::S,     [&]() { std::cout << "S\n"; }),
        action(sf::Keyboard::D,     [&]() { std::cout << "D\n"; }),

        action(sf::Keyboard::Space, [&]() { std::cout << "Space\n"; }),

        action(sf::Mouse::Left,     [&]() { std::cout << "Mouse\n"; })
    };


    while (window.isOpen())
    {
        for (auto& action : actions){
            action();
        }

        window.clear();
        object.draw(window);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}