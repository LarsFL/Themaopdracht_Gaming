#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <ctime>

#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"
#include "Code/Game engine/World Speed Systems/view.hpp"
#include "Code/Game engine/Object systems/Player.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"
#include "Code/Setup/InitializeAnimations.hpp"
#include "Code/Game engine/Animation systems/AnimationStates.hpp"
#include "Code/Game engine/Object systems/Projectile.hpp"

#include "Code/Setup/GameState.hpp"
#include "Code/Setup/InitializeUI.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");
    window.setFramerateLimit(60);
    sf::View fixed = window.getView();
    std::map<std::string, AnimationStates> animationsMap;
    sf::View mainView;

    InitializePlayerAnimations(animationsMap);
    InitializeSmallAlienAnimations(animationsMap);
    bool escapeUp = true;

    mainView.setCenter(sf::Vector2f(600.f, 384.f));
    mainView.setSize(sf::Vector2f(1280.f, 720.f));
    mainView.setViewport(sf::FloatRect(0, 0, 1, 1));
    window.setView(mainView);

    std::string pathBackground = "../Assets/Test/background2.png";
    GameObject background{ pathBackground, sf::Vector2f{-250, -250}, sf::Vector2f{1.2, 1.4}, 5, false };

    std::string imgLoc = "../Assets/Objects/smallAstronaut.png";
    GameObject testObject(imgLoc, sf::Vector2f(500, 100), sf::Vector2f(15, 15), 200.0, false, true);
    testObject.setAnimationStates(&animationsMap["player"]);

    std::string pathGround = "../Assets/Test/green_button01.png";
    std::vector<GameObject> groundObjectList;
    float widthValue = -190;
    float widthG = 190;

    for (unsigned int i = 0; i < 10; i++) {
        groundObjectList.push_back(GameObject{ pathGround, sf::Vector2f{widthValue, 675}, sf::Vector2f{1, 1}, 5, false });
        widthValue += widthG;
    }
    groundObjectList.push_back(GameObject{ pathGround, sf::Vector2f{widthValue, 500}, sf::Vector2f{1, 1}, 5, false });

    GameState state{};

    InitializeUI(window, fixed, state);

    action actions[] = {
        //action(sf::Keyboard::Up,    [&]() { std::cout << "Up\n"; }),
        //action(sf::Keyboard::Left,  [&]() { std::cout << "Left\n"; }),
        //action(sf::Keyboard::Down,  [&]() { std::cout << "Down\n"; }),
        //action(sf::Keyboard::Right, [&]() { std::cout << "Right\n"; }),

        //action(sf::Keyboard::W,     [&]() { std::cout << "W\n"; }),
        //action(sf::Keyboard::A,     [&]() { std::cout << "A\n"; }),
        //action(sf::Keyboard::S,     [&]() { std::cout << "S\n"; }),
        //action(sf::Keyboard::D,     [&]() { std::cout << "D\n"; }),

        //action(sf::Mouse::Left,     [&]() { std::cout << "Mouse\n"; }),
        action(sf::Keyboard::Escape,[&]() { if (escapeUp) { state.handleEscape(); escapeUp = false; } }),
        action([&]() {return !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape); }, [&]() { escapeUp = true; })
    };

    auto previous = std::chrono::system_clock::now();
    auto lag = 0.0;
    float msPerLoop = 16.33;
    float minSpeed = 0.5;

    std::string smallAlienSprite = "../Assets/Objects/smallAlien.png";
    GameObject smallAlien(smallAlienSprite, sf::Vector2f(500, 300), sf::Vector2f(5, 5), 200.0, false, true);
    smallAlien.setAnimationStates(&animationsMap["smallAlien"]);

    std::string smallAstronautSprite = "../Assets/Objects/smallAstronaut.png";
    GameObject smallAstronaut(smallAstronautSprite, sf::Vector2f(700, 300), sf::Vector2f(5, 5), 200.0, false, true);
    smallAstronaut.setAnimationStates(&animationsMap["player"]);

    animationsMap["smallAlien"].setState(PossibleStates::DEATH);

    std::string testPlaatje = "../Assets/Test/testplaatje.png";
    Player player{ testPlaatje, sf::Vector2f{0,250}, sf::Vector2f{.1,.1}, 5, false, window, groundObjectList };
    player.setVelocity(sf::Vector2f{ 0.0, 1.1 });

    while (window.isOpen()) {
        // Always take the same time step per loop. (should work now)
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> elapsed = current - previous;
        previous = current;
        lag += elapsed.count();

        for (auto& action : actions) {
            action();
        }

        window.clear();

        while (lag >= msPerLoop) {
            if (state.getState() == game_states::PLAYING) {
                // Move the view at an ever increasing speed and move the background along with the same speed.
                float viewMoveSpeed = update_view_position(mainView, window, minSpeed);
                move_object_with_view(background, viewMoveSpeed, minSpeed);

                // Check if selected object is within the bouns of the selected view
                sf::FloatRect view2 = getViewBounds(mainView);
                GameObject firstGroundObject = groundObjectList[0];
                GameObject secondGroundObject = groundObjectList[1];
                sf::FloatRect rectObject = groundObjectList[0].getGlobalBounds();
                static float minLengthGroundObjects = widthG * (groundObjectList.size() - 1);

                if (rectObject.intersects(view2)) {
                    //std::cout << "y\n";
                }
                else {
                    firstGroundObject = secondGroundObject;
                    groundObjectList.erase(groundObjectList.begin());

                    groundObjectList.push_back(GameObject{ pathGround, sf::Vector2f{minLengthGroundObjects, 675}, sf::Vector2f{1, 1}, 5, false });
                    minLengthGroundObjects += widthG;
                    widthValue += widthG;

                    groundObjectList[(groundObjectList.size() - 1)].draw(window);
                }
                player.update();
            }

            lag -= msPerLoop;
        }

        window.setView(mainView);
        background.draw(window);

        for (GameObject& current_object : groundObjectList) {
            current_object.draw(window);
        }
        
        auto bounds = getViewBounds(mainView);
        player.drawProjectiles(bounds);

        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos, fixed);
        state.updateUI(translated_pos);

        player.draw(window);
        window.setView(fixed);
        state.draw(window);

        smallAlien.draw(window);
        smallAstronaut.draw(window);

        window.display();
        window.setView(mainView);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || state.closeGame) {
                window.close();
            }
        }

    }
    return 0;
}
