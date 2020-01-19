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

    std::string pathBackground = "../Assets/Test/background2.png";
    GameObject background{ pathBackground, sf::Vector2f{-250, -250}, sf::Vector2f{1.2, 1.4}, 5, false };

    std::string pathGround = "../Assets/Test/green_button01.png";
    std::vector<GameObject> groundObjectList;
    float widthValue = -190;
    float widthG = 190;

    for (unsigned int i = 0; i < 5; i++) {
        groundObjectList.push_back(GameObject{ pathGround, sf::Vector2f{widthValue, 675}, sf::Vector2f{1, 1}, 5, false });
        widthValue += widthG;
    }

    std::string button = "../Assets/Test/grey_button01.png";
    std::string replaceButton = "../Assets/Test/green_button01.png";
    Button testButton{ button, replaceButton, sf::Vector2f { 0, 0}, sf::Vector2f{1,1.5 }, [&]{std::cout << "Test"; } };
    GameState state{};

    InitializeUI(window, fixed, state);

    action actions[] = {
        action(sf::Keyboard::Up,    [&]() { mainView.move(-1, 0); window.setView(mainView); }),
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
            GameObject firstGroundObject = groundObjectList[0];
            GameObject secondGroundObject = groundObjectList[1];
            sf::FloatRect rectObject = groundObjectList[0].getGlobalBounds();
            static float minLengthGroundObjects = widthG * (groundObjectList.size() - 1);
            // Tet of pointer werkt als lijst voor ground objecten om de textures er goed in te krijgen.
            if (rectObject.intersects(view2)) {
                //std::cout << "y\n";
            }
            else {
                firstGroundObject = secondGroundObject;
                groundObjectList.erase(groundObjectList.begin());

                std::cout << "L: " << groundObjectList.size() << "\n";
                std::cout << "WV: " << minLengthGroundObjects << "\n";
                groundObjectList.push_back(GameObject{ pathGround, sf::Vector2f{minLengthGroundObjects, 675}, sf::Vector2f{1, 1}, 5, false });
                minLengthGroundObjects += widthG;
                widthValue += widthG;

                groundObjectList[(groundObjectList.size() - 1)].draw(window);

                std::cout << "L: " << groundObjectList.size() << "\n";

                //std::cout << "n\n";
            }    
            
            
            }
            lag -= elapsed.count();
        }

        window.clear();
        //
        window.setView(mainView);
        background.draw(window);

        for (GameObject& current_object : groundObjectList) {
            current_object.draw(window);
        }

        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos, fixed);
        state.updateUI(translated_pos);


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

