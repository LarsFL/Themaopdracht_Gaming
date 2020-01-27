#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <ctime>
#include <deque>
#include <memory>


#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"
#include "Code/Game engine/World Speed Systems/view.hpp"
#include "Code/Game engine/World generation systems/ObjectBlock.hpp"
#include "Code/Game engine/World generation systems/GenerateBlock.hpp"
#include "Code/Game engine/Object systems/Player.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"
#include "Code/Setup/InitializeAnimations.hpp"
#include "Code/Game engine/Animation systems/AnimationStates.hpp"
#include "Code/Game engine/Object systems/Projectile.hpp"

#include "Code/Setup/GameState.hpp"
#include "Code/Setup/InitializeUI.hpp"
#include "Code/Setup/InitializeBlocks.hpp"
#include "Code/Setup/InitializeSounds.hpp"

#include "Code/Game engine/Tile systems/TextureManager.hpp";

#include "Code/Game engine/Audio systems/AudioManager.hpp";

int main() {
    int width = sf::VideoMode::getDesktopMode().width;
    int height = sf::VideoMode::getDesktopMode().height;
    //sf::RenderWindow window(sf::VideoMode(width, height), "Mars Runner", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(width, height), "Mars Runner", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::View fixed = window.getView();
    std::map<std::string, AnimationStates> animationsMap;
    sf::View mainView;

    InitializePlayerAnimations(animationsMap);
    InitializeSmallAlienAnimations(animationsMap);
    InitializeGreenAlienAnimations(animationsMap);
    InitializeSateliteAnimations(animationsMap);

    bool escapeUp = true;
    bool test = true;
    mainView.setCenter(sf::Vector2f(600.f, 384.f));
    mainView.setSize(sf::Vector2f(1280.f, 720.f));
    mainView.setViewport(sf::FloatRect(0, 0, 1, 1));
    window.setView(mainView);

    //std::string pathBackground = "../Assets/Test/background2.png";
    //GameObject background{ pathBackground, sf::Vector2f{-250, -250}, sf::Vector2f{1.2, 1.4}, 5, false };
    std::string pathBackground = "../Assets/Objects/newBackground.jpg";
    GameObject background{ pathBackground, sf::Vector2f{-250, -250}, sf::Vector2f{0.78, 1.4}, 5, false };


    std::string pathGround = "../Assets/Test/green_button01.png";
    std::deque<ObjectBlock> groundObjectList;

    GenerateBlock generator = {};
    TextureManager manager = {};
    AudioManager audio = {};

    generateBlocks(generator, manager);
    initializeSounds(audio);

    float widthValue = -190;
    float widthG = 32;

    for (unsigned int i = 0; i < 15; i++) {
        ObjectBlock generatedBlock = generator.generate();
        generatedBlock.setPositions(sf::Vector2f(widthValue, 0), 32);
        groundObjectList.push_back(generatedBlock);
        widthValue += (widthG * 5);
    }

    GameState state{};

    InitializeUI(window, fixed, state);

    action actions[] = {
        action(sf::Keyboard::Escape,[&]() { if (escapeUp) { state.handleEscape(); escapeUp = false;} }),
        action([&]() {return !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape); }, [&]() { escapeUp = true;})
    };

    auto previous = std::chrono::system_clock::now();
    auto lag = 0.0;
    float msPerLoop = 16.33;
    float minSpeed = 0.5;


    std::string playerSpriteSheet = "../Assets/Objects/smallAstronaut.png";
    Player player{ playerSpriteSheet, sf::Vector2f{0,400}, sf::Vector2f{2,2}, 5, false, true, window, groundObjectList, audio };
    player.setAnimationStates(&animationsMap["player"]);
    animationsMap["player"].setState(PossibleStates::WALK);
    player.setVelocity(sf::Vector2f{ 0.0, 2 });

    while (window.isOpen()) {
        // Always take the same time step per loop. (should work now)
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> elapsed = current - previous;
        previous = current;
        lag += elapsed.count();


        window.clear();

        while (lag >= msPerLoop) {

            for (auto& action : actions) {
                action();
            }

            //qualety of life for us, in main game?
            if (state.getState() == game_states::MAIN_MENU && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    
                }
                state.setState(game_states::PLAYING);
            }

            if (state.getState() == game_states::PLAYING) {
                // Move the view at an ever increasing speed and move the background along with the same speed.
                update_view_position(mainView, window, minSpeed);
                float viewMoveSpeed = getViewMoveSpeed();
                move_object_with_view(background, viewMoveSpeed, minSpeed);

                // Check if selected object is within the bouns of the selected view
                sf::FloatRect view2 = getViewBounds(mainView);
                auto firstGroundObject = groundObjectList[0];
                sf::FloatRect rectObject = firstGroundObject.getGlobalBounds(); // Get global bounds van blok
                if (!(rectObject.intersects(view2))) {
                    // Eigen functie om destructors aan te roepen
                    groundObjectList.pop_front();
                    if (test) {
                        ObjectBlock generatedBlock = generator.generate();
                        generatedBlock.setPositions(sf::Vector2f(widthValue, 0), 32);
                        groundObjectList.push_back(generatedBlock);
                        widthValue += (widthG * 5);
                        //test = false;
                    }
                }
                /*else {
                    firstGroundObject = secondGroundObject;
                    groundObjectList.erase(groundObjectList.begin());

                    groundObjectList.push_back(GameObject{ pathGround, sf::Vector2f{minLengthGroundObjects, 675}, sf::Vector2f{1, 1}, 5, false });
                    minLengthGroundObjects += widthG;
                    widthValue += widthG;

                    groundObjectList[(groundObjectList.size() - 1)].draw(window);
                }*/ //@Lars, wat moet hiermee gebeuren?
                player.update(minSpeed);
                player.setPlayerAnimationState(animationsMap);
            }

                lag -= msPerLoop;
        }

            window.setView(mainView);
            background.draw(window);

            for (auto& current_object : groundObjectList) {
                current_object.draw(window);
            }

            auto bounds = getViewBounds(mainView);
           player.drawProjectiles(bounds);

            auto mouse_pos = sf::Mouse::getPosition(window);
            auto translated_pos = window.mapPixelToCoords(mouse_pos, fixed);
            state.updateUI(translated_pos);

            state.updateUIElement(game_states::PLAYING, "ScoreValueText", std::to_string(player.getPoints()));
            state.updateUIElement(game_states::PAUSED, "PausedScoreValueText", std::to_string(player.getPoints()));

            player.draw(window);
            window.setView(fixed);
            state.draw(window);


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
 