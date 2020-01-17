#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"
//#include "Code/Setup/InitializeAnimations.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");

    sf::IntRect loc(1, 1, 37, 41);
    Animation Walking(loc, 11, 38);
    AnimationStates smallAstronaut(40);
    smallAstronaut.addAnimation(PossibleStates::WALK, Walking);

    std::string imgLoc = "../Assets/Objects/smallAstronaut.png";
    GameObject testObject(imgLoc, sf::Vector2f(500, 300), sf::Vector2f(1, 1), 200.0, false, true);
    testObject.setAnimationStates(&smallAstronaut);

    
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
        testObject.draw(window);
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