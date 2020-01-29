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
#include "Code/Game engine/Object systems/randomNumber.hpp"
#include "Code/Game engine/World generation systems/ObjectBlock.hpp"
#include "Code/Game engine/World generation systems/GenerateBlock.hpp"
#include "Code/Game engine/Object systems/Player.hpp"
#include "Code/Game engine/Object systems/PickUp.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"
#include "Code/Setup/InitializeAnimations.hpp"
#include "Code/Game engine/Animation systems/AnimationStates.hpp"
#include "Code/Game engine/Object systems/Projectile.hpp"
#include "Code/Game engine/Object systems/EnemyObject.hpp"

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
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mars Runner", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::View fixed = window.getView();
    std::map<std::string, AnimationStates> animationsMap;
    sf::View mainView;

    InitializePlayerAnimations(animationsMap);
    InitializeSmallAlienAnimations(animationsMap);
    InitializeGreenAlienAnimations(animationsMap);
    InitializeSateliteAnimations(animationsMap);

    bool escapeUp = true;
    mainView.setCenter(sf::Vector2f(600.f, 384.f));
    mainView.setSize(sf::Vector2f(1280.f, 720.f));
    mainView.setViewport(sf::FloatRect(0, 0, 1, 1));
    window.setView(mainView);

    std::string pathBackground = "../Assets/Objects/newBackground.jpg";
    GameObject background{ pathBackground, sf::Vector2f{-250, -250}, sf::Vector2f{0.78, 1.4}, 5, false };


    std::string pathGround = "../Assets/Test/green_button01.png";
    std::deque<ObjectBlock> groundObjectList;

    GenerateBlock generator = {};
    TextureManager manager = {};
    AudioManager audio = {};

    generateBlocks(generator, manager);
    initializeSounds(audio);

    std::string coinPath = "../Assets/Objects/coin.png";
    Texture coinTex{ coinPath };
    manager.addTexture(2, coinTex);

    float widthValue = -190;
    float widthG = 32;

    //de blokken aan het begin van de game
    /*for (unsigned int i = 0; i < 15; i++) {
        ObjectBlock generatedBlock = generator.generate();
        generatedBlock.setPositions(sf::Vector2f(widthValue, 0), 32);
        groundObjectList.push_back(generatedBlock);
        widthValue += (widthG * 5);
    }*/
    for (unsigned int i = 0; i < 12; i++) {
        ObjectBlock generatedBlock = generator.generateStart();
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
    float minSpeed = 3;
    sf::Vector2f newPosition = { 0.0,0.0 };

    std::string playerSpriteSheet = "../Assets/Objects/smallAstronaut.png";
    Player player{ playerSpriteSheet, sf::Vector2f{580,550}, sf::Vector2f{2,2}, 5, false, true, window, groundObjectList, mainView, state, audio };

    player.setAnimationStates(&animationsMap["player"]);
    animationsMap["player"].setState(PossibleStates::IDLE);
    player.setVelocity(sf::Vector2f{ 0.0, 2 });
    
    std::deque<PickUp> coinList;

    coinList.push_back(PickUp{ manager, 2, sf::Vector2f{getRandomNumber(700, 1100), 100}, 
                                           sf::Vector2f{.03,.03}, 
                                           sf::Vector2f{0.0, 5}, 5, false, false, window });


    std::string smallAlienSpriteSheet = "../Assets/Objects/smallAlien.png";
    Enemy smallAlien{smallAlienSpriteSheet, sf::Vector2f{1200,700}, sf::Vector2f{2,2}, 5, true, true };
    smallAlien.setAnimationStates(&animationsMap["smallAlien"]);
    animationsMap["smallAlien"].setState(PossibleStates::IDLE);
    smallAlien.setVelocity(sf::Vector2f{ 0.0, 2 });
    smallAlien.setAcceleration(sf::Vector2f{ 0.0, 2 });
    

    while (window.isOpen()) {
        // Always take the same time step per loop.
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> elapsed = current - previous;
        previous = current;
        lag += elapsed.count();


        window.clear();

        while (lag >= msPerLoop) {
            float increaseValue = mainView.getCenter().x;

            for (auto& action : actions) {
                action();
            }

            //qualety of life for us, in main game?
            if (state.getState() == game_states::MAIN_MENU && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    
                }
                state.setState(game_states::PLAYING);
            }

            //freese palyer animation if paused
            if (state.getState() == game_states::PAUSED) {
                animationsMap["player"].setPaused(true);
            }
            else {
                animationsMap["player"].setPaused(false);
            }

            if (state.getState() == game_states::PLAYING) {
                // Move the view at an ever increasing speed and move the background along with the same speed.
                update_view_position(mainView, window, minSpeed);
                float viewMoveSpeed = getViewMoveSpeed();
                move_object_with_view(background, viewMoveSpeed, minSpeed);

                // Check if selected object is within the bouns of the selected view
                sf::FloatRect view2 = getViewBounds(mainView);
                auto firstGroundObject = groundObjectList[0];
                sf::FloatRect rectObject = firstGroundObject.getGlobalBounds();
                if (!(rectObject.intersects(view2))) {
                    groundObjectList.pop_front();
                    ObjectBlock generatedBlock = generator.generate();
                    generatedBlock.setPositions(sf::Vector2f(widthValue, 0), 32);
                    groundObjectList.push_back(generatedBlock);
                    widthValue += (widthG * (generatedBlock.getWidth() + 1)); //widthValue += (widthG * 5);
                }

                player.update(minSpeed);
                player.setPlayerAnimationState(animationsMap);

                if (coinList.size() > 0) {
                    if (coinList[0].destroyObjectOnInteract(coinList, player, mainView)) {
                        float tempValue = increaseValue * 2.5;
                        newPosition = sf::Vector2f{ getRandomNumber(tempValue + 600, tempValue + 1200), 100 };
                    }
                }

                if (coinList.size() == 0) {
                    if (player.getGlobalBounds().left + 1750 > newPosition.x) {
                        coinList.push_back(PickUp{ manager, 2, newPosition,
                                                                sf::Vector2f{0.03,0.03},
                                                                sf::Vector2f{0.0, 7.5}, 5, false, false, window });
                    }
                }

                if (coinList.size() > 0) {
                    coinList[0].move(coinList[0].getMoveSpeed());
                }
                // TODO Coins vallen niet helemaal door de onderkant,
                // TODO Bij death, back to menu werkt niet,
                for (auto& groundObject : groundObjectList) {
                    if (coinList.size() > 0) {
                        if (isObjOnGround(coinList[0], groundObject)) {
                            coinList[0].setMoveSpeed(sf::Vector2f{ 0.0, 0.0 });
                        }
                    }
                }
            }

            if (state.getState() == game_states::MAIN_MENU) {
                if (state.getReplay()) {           
                    mainView.setCenter(sf::Vector2f(600.f, 384.f));
                    background.jump(sf::Vector2f{ -250, -250 });
                    widthValue = -190;
                    groundObjectList.clear();
                    for (unsigned int i = 0; i < 12; i++) {
                        ObjectBlock generatedBlock = generator.generateStart();
                        generatedBlock.setPositions(sf::Vector2f(widthValue, 0), 32);
                        groundObjectList.push_back(generatedBlock);
                        widthValue += (widthG * 5);
                    }
                    update_view_position(mainView, window, minSpeed, true);
                    float viewMoveSpeed = getViewMoveSpeed();
                    move_object_with_view(background, viewMoveSpeed, minSpeed);
                    state.setReplay(false);
                    player.setPlayerState(playerStates::IDLE);
                    player.jump(sf::Vector2f{ 580,550 });
                    player.update(minSpeed);
                    player.setPlayerAnimationState(animationsMap);

                    float increaseValue = mainView.getCenter().x;
                    std::cout << "size: " << coinList.size() << "\n";
                    if (coinList.size() > 0) {
                        std::cout << "yooeo\n";
                        coinList.pop_back();
                        coinList.push_back(PickUp{ manager, 2, sf::Vector2f{getRandomNumber(increaseValue + 600, increaseValue + 1200), 100},
                                                               sf::Vector2f{0.03,0.03},
                                                               sf::Vector2f{0.0, 5}, 5, false, false, window });

                        coinList[0].setMoveSpeed(sf::Vector2f{ 0.0, 5 });
                    }
                    else {
                        coinList.push_back(PickUp{ manager, 2, sf::Vector2f{getRandomNumber(increaseValue + 600, increaseValue + 1200), 100},
                                       sf::Vector2f{0.03,0.03},
                                       sf::Vector2f{0.0, 5}, 5, false, false, window });

                        coinList[0].setMoveSpeed(sf::Vector2f{ 0.0, 5 });
                    }

                    newPosition = { 0.0,0.0 };
                }
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

            if (coinList.size() > 0) {
                for (PickUp& current_object : coinList) {
                    current_object.draw(window);
                }
            }

            auto mouse_pos = sf::Mouse::getPosition(window);
            auto translated_pos = window.mapPixelToCoords(mouse_pos, fixed);
            state.updateUI(translated_pos);

        state.updateUIElement(game_states::PLAYING, "ScoreValueText", std::to_string(state.getScore()));
        state.updateUIElement(game_states::PAUSED, "PausedScoreValueText", std::to_string(state.getScore()));
        state.updateUIElement(game_states::GAME_OVER, "GameOverScoreValue", std::to_string(state.getScore()));

            player.draw(window);
            window.setView(fixed);
            state.draw(window);
            window.display();
            window.setView(mainView);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (state.getEnterText() && (event.type == sf::Event::TextEntered)) {
                sf::String text = state.getText();
                if (event.text.unicode == '\b') {
                    if (text.getSize() > 0) {
                        text.erase(text.getSize() - 1, 1);
                    }
                }
                else {
                    if (text.getSize() < 10) {
                        text += event.text.unicode;
                    }
                }
                state.updateUIElement(game_states::SAVE_SCORE, "enterField", text);
                state.setEnteredString(text);
            }
            if (event.type == sf::Event::Closed || state.closeGame) {
                window.close();
            }
        }
    }
    return 0;
}
 