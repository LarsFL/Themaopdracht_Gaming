#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <ctime>

#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"
#include "Code/Game engine/World Speed Systems/view.hpp"

#include "Code/Setup/GameState.hpp"
#include "Code/Setup/InitializeUI.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    sf::View fixed = window.getView();
    sf::View mainView;

    bool escapeUp = true;

    mainView.setCenter(sf::Vector2f(600.f, 384.f));
    mainView.setSize(sf::Vector2f(1280.f, 720.f));
    mainView.setViewport(sf::FloatRect(0, 0, 1, 1));
    window.setView(mainView);

    sf::CircleShape shape(50.f);
    shape.setPosition(sf::Vector2f(840, 260));
    shape.setFillColor(sf::Color::Green);
    
    std::string thing = "../Assets/Test/Astronaut_idle.png";
    GameObject object{ thing, sf::Vector2f{1200, 500}, sf::Vector2f{2,2}, 5 };

    std::string path = "../Assets/Test/background2.png";
    GameObject background{ path, sf::Vector2f{-250, -250}, sf::Vector2f{1.2, 1.4}, 5, false };

    GameState state{};

    GameObject game_objects[] = { object };
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

    auto previous = std::chrono::system_clock::now();
    auto lag = 0.0;

    while (window.isOpen()) {
        // Always take the same time step per loop. (should work)
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed = current - previous;
        previous = current;
        lag += elapsed.count();

        for (auto& action : actions) {
            action();
        }

        while (lag >= elapsed.count()) {
            if (state.getState() == game_states::PLAYING) {
                // Move the view at an ever increasing speed and move the background along with the same speed.
                float viewMoveSpeed = update_view_position(mainView, window, elapsed.count());
                move_object_with_view(background, viewMoveSpeed);

                // Check if selected object is within the bouns of the selected view
                sf::FloatRect view2 = getViewBounds(mainView);
                auto rect = object.getGlobalBounds();

                if (rect.intersects(view2)) {
                    //std::cout << "y\n";
                }
                else {
                    //std::cout << "n\n";
                }

                /* Zet hier je code. */
            }
            
            lag -= elapsed.count();
        }

        window.clear();
        //
        window.setView(mainView);
        background.draw(window);

        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos, fixed);
        state.updateUI(translated_pos);

        for (auto& current_object : game_objects) {
            current_object.draw(window);
        }


        window.setView(fixed);
        state.draw(window);

        window.display();
        window.setView(mainView);

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed || state.closeGame) {
                window.close();
            }
        }
    }

    return 0;
}

