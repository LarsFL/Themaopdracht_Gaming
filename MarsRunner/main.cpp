#include <SFML/Graphics.hpp>
#include <vector>

#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    std::string thing = "../Assets/Test/Astronaut_idle.png";
    GameObject object{ thing, sf::Vector2f{0,0}, sf::Vector2f{2,2}, 5 };

    std::string button = "../Assets/Test/grey_button01.png";
    std::string replaceButton = "../Assets/Test/green_button01.png";
    Button testButton{ button, replaceButton, sf::Vector2f { 0, 0}, sf::Vector2f{1,1.5 }, [&]{std::cout << "Test"; } };

    std::string fontLocation = "../Assets/Fonts/Mars.otf";
    std::string textext = "Hallo123";
    Text testText{ fontLocation, textext, sf::Vector2f{500,200}, sf::Vector2f{1,1}, [&] {std::cout << "Text clicc"; } };

    std::vector<UIElement*> UIElements = { &testButton, &testText };

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

    unsigned int i = 0;

    while (window.isOpen())
    {
        for (auto& action : actions){
            action();
        }

        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos);
        for (auto& object : UIElements) {
            if (object->getGlobalBounds().contains(translated_pos)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    object->onClick();
                }
                else {
                    object->onHover();
                }
            }
        }

        testText.setText(std::to_string(i));


        window.clear();
        object.draw(window);
        testButton.draw(window);
        testText.draw(window);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::sleep(sf::milliseconds(10));
        i++;
    }

    return 0;
}