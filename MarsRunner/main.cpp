#include <SFML/Graphics.hpp>
#include <vector>

#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"

#include "Code/Setup/GameState.hpp"
#include "Code/Setup/InitializeUI.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::View fixed = window.getView();
    sf::View game = fixed;

    bool escapeUp = true;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    GameState state{};

    InitializeUI(window, fixed, state);

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

        action(sf::Mouse::Left,     [&]() { std::cout << "Mouse\n"; }),

        action(sf::Keyboard::Escape,[&]() { if (escapeUp) { state.handleEscape(); escapeUp = false; } }),
        action([&]() {return !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape); }, [&]() { escapeUp = true; })
    };

    while (window.isOpen())
    {
        for (auto& action : actions){
            action();
        }

        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos);
        state.updateUI(translated_pos);

        window.clear();
        window.setView(game);
        window.setView(fixed);
        state.draw(window);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed || state.closeGame) {
                window.close();
            }
        }

        sf::sleep(sf::milliseconds(10));
    }

    return 0;
}