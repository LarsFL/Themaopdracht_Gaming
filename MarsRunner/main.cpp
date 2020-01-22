#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>

#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"
#include "Code/Setup/InitializeAnimations.hpp"
#include "Code/Game engine/Animation systems/AnimationStates.hpp"

int main()
{
    std::map<std::string, AnimationStates> animationsMap;

    InitializePlayerAnimations(animationsMap);

    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");

    std::string imgLoc = "../Assets/Objects/smallAstronaut.png";
    GameObject testObject(imgLoc, sf::Vector2f(500, 100), sf::Vector2f(15, 15), 200.0, false, true);
    testObject.setAnimationStates(&animationsMap["player"]);

    action actions[] = {
        action(sf::Keyboard::Up,    [&]() { std::cout << "Up\n"; }),
        action(sf::Keyboard::Left,  [&]() { std::cout << "Left\n"; }),
        action(sf::Keyboard::Down,  [&]() { std::cout << "Down\n"; }),
        action(sf::Keyboard::Right, [&]() { std::cout << "Right\n";}),

        action(sf::Keyboard::W,     [&]() { std::cout << "W\n"; }),
        action(sf::Keyboard::A,     [&]() { std::cout << "A\n"; }),
        action(sf::Keyboard::S,     [&]() { std::cout << "S\n"; }),
        action(sf::Keyboard::D,     [&]() { std::cout << "D\n"; }),

        action(sf::Keyboard::Space, [&]() { std::cout << "Space\n";}),

        action(sf::Mouse::Left,     [&]() { std::cout << "Mouse\n"; }),

        action(sf::Keyboard::Num1,    [&]() { animationsMap["player"].setState(PossibleStates::WALK); }),
        action(sf::Keyboard::Num2,    [&]() { animationsMap["player"].setState(PossibleStates::SHOOT); }),
        action(sf::Keyboard::Num3,    [&]() { animationsMap["player"].setState(PossibleStates::IDLE); }),
        action(sf::Keyboard::Num4,    [&]() { animationsMap["player"].setState(PossibleStates::START_SHOOT_WALK); }),
        action(sf::Keyboard::Num5,    [&]() { animationsMap["player"].setState(PossibleStates::JUMP_START_IMPACT); }),
        action(sf::Keyboard::Num6,    [&]() { animationsMap["player"].setState(PossibleStates::DAMAGED); }),
        action(sf::Keyboard::Num7,    [&]() { animationsMap["player"].setState(PossibleStates::DEATH); })

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