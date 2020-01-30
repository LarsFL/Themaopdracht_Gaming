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
#include "Code/Game engine/Object systems/EnemyObject.hpp"
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
    sf::RenderWindow window(sf::VideoMode(width, height), "Mars Runner", sf::Style::Default);

    window.setVerticalSyncEnabled(true);
    sf::View fixed = window.getView();
    sf::View mainView;

    mainView.setCenter(sf::Vector2f(600.f, 384.f));
    mainView.setSize(sf::Vector2f(1280.f, 720.f));
    mainView.setViewport(sf::FloatRect(0, 0, 1, 1));
    window.setView(mainView);

    GenerateBlock generator = {};
    TextureManager manager = {};
    AudioManager audio = {};
    GameState state{};

    generateBlocks(generator, manager);
    initializeSounds(audio);
    InitializeUI(window, fixed, state);

    auto previous = std::chrono::system_clock::now();
    auto lag = 0.0;
    float msPerLoop = 16.33;
    float minSpeed = 3;
    float widthValue = -190;
    float widthG = 32;
    sf::Vector2f newCoinPosition = { 0.0,0.0 };
    sf::Vector2f newEnemyPosition = { 0.0,0.0 };

    std::map<std::string, AnimationStates> animationsMap;

    std::deque<ObjectBlock> groundObjectList;
    std::deque<PickUp> coinList;
    std::deque<Enemy> enemyList;

    InitializePlayerAnimations(animationsMap);
    InitializeSmallAlienAnimations(animationsMap);
    InitializeGreenAlienAnimations(animationsMap);
    InitializeSateliteAnimations(animationsMap);

    // Generate initial flat land to start the game on
    for (unsigned int i = 0; i < 12; i++) {
        ObjectBlock generatedBlock = generator.generateStart();
        generatedBlock.setPositions(sf::Vector2f(widthValue, 0), 32);
        groundObjectList.push_back(generatedBlock);
        widthValue += (widthG * 5);
    }

    std::string pathBackground = "../Assets/Objects/newBackground.jpg";
    GameObject background{ pathBackground, sf::Vector2f{-250, -250}, sf::Vector2f{0.78, 1.4}, 5, false };

    std::string playerSpriteSheet = "../Assets/Objects/smallAstronaut.png";
    Player player{ playerSpriteSheet, sf::Vector2f{580,550}, sf::Vector2f{2,2}, 5, false, true, window, groundObjectList, mainView, state, audio };
    player.setAnimationStates(&animationsMap["player"]);
    animationsMap["player"].setState(PossibleStates::IDLE);
    player.setVelocity(sf::Vector2f{ 0.0, 2 });
    
    coinList.push_back(PickUp{ manager, 2, sf::Vector2f{getRandomNumber(700, 1100), 500}, 
                                           sf::Vector2f{.03,.03}, 
                                           sf::Vector2f{0.0, 5}, 5, false, false, window, state, audio });

    enemyList.push_back(Enemy { manager, 3, sf::Vector2f{getRandomNumber(1700, 1900),100},
                                            sf::Vector2f{2,2},
                                            sf::Vector2f{0.0, 5}, 5, false, true, state, window, audio });
    enemyList[0].setAnimationStates(&animationsMap["smallAlien"]);
    animationsMap["smallAlien"].setState(PossibleStates::IDLE);

    while (window.isOpen()) {
        // Always take the same time step per loop.
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<float, std::milli> elapsed = current - previous;
        previous = current;
        lag += elapsed.count();

        window.clear();

        while (lag >= msPerLoop) {
            float increaseValue = mainView.getCenter().x;

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

                player.update(minSpeed, enemyList);

                if (coinList.size() > 0) {
                    if (coinList[0].destroyObjectOnInteract(coinList, player.getGlobalBounds(), mainView)) {
                        float tempValue = increaseValue * 1.3;
                        newCoinPosition = sf::Vector2f{ getRandomNumber(tempValue + 600, tempValue + 1200), 100 };
                    }
                }

                if (coinList.size() == 0) {
                    if (player.getGlobalBounds().left + 1750 > newCoinPosition.x) {
                        coinList.push_back(PickUp{ manager, 2, newCoinPosition,
                                                                sf::Vector2f{0.03,0.03},
                                                                sf::Vector2f{0.0, 3}, 5, false, false, window, state, audio });
                    }
                }

                if (coinList.size() > 0) {
                    coinList[0].move(coinList[0].getMoveSpeed());
                }


                // Destroy enemy object when the player interacts with it, or the enemy is out of bounds.
                if (enemyList.size() > 0) {
                    if (player.deathByEnemy(enemyList) || enemyList[0].enemyOutOfBounds(enemyList, mainView)) {
                        float tempValue = increaseValue * 1.1;
                        newEnemyPosition = sf::Vector2f{ getRandomNumber(tempValue + 600, tempValue + 1200), 100 };
                    }
                }

                // Spawn enemy when player is getting close to position of enemy
                if (enemyList.size() == 0) {
                    if (player.getGlobalBounds().left + 1750 > newEnemyPosition.x) {
                        enemyList.push_back(Enemy{ manager, 3, newEnemyPosition,
                                                                sf::Vector2f{2,2},
                                                                sf::Vector2f{0.0, 5}, 5, false, true, state, window, audio });
                        enemyList[0].setAnimationStates(&animationsMap["smallAlien"]);
                        animationsMap["smallAlien"].resetCurrentAnimation();
                        animationsMap["smallAlien"].setState(PossibleStates::IDLE);
                    }
                }

                // Move the enemy
                if (enemyList.size() > 0) {
                    enemyList[0].move(enemyList[0].getMoveSpeed());
                }

                player.setPlayerAnimationState(animationsMap);

                for (auto& groundObject : groundObjectList) {
                    if (coinList.size() > 0) {
                        if (isObjOnGround(coinList[0], groundObject)) {
                            coinList[0].setMoveSpeed(sf::Vector2f{ 0.0, 0.0 });
                        }
                    }
                }

                // If enemy hits the ground, stop moving the enemy.
                // TODO Zet deze in update van enemy
                for (auto& groundObject : groundObjectList) {
                    if (enemyList.size() > 0) {
                        if (isObjOnGround(enemyList[0], groundObject)) {
                            enemyList[0].setMoveSpeed(sf::Vector2f{ 0.0, 0.0 });
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

                    player.clearProjectiles();

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

                    animationsMap["player"].resetCurrentAnimation();
                    animationsMap["smallAlien"].resetCurrentAnimation();

                    player.setPlayerState(playerStates::IDLE);
                    player.jump(sf::Vector2f{ 580,550 });
                    player.update(minSpeed, enemyList);
                    player.setPlayerAnimationState(animationsMap);



                    float increaseValue = mainView.getCenter().x;

                    if (coinList.size() > 0) {
                        coinList.pop_back();
                        coinList.push_back(PickUp{ manager, 2, sf::Vector2f{getRandomNumber(increaseValue + 600, increaseValue + 1200), 100},
                                                               sf::Vector2f{0.03,0.03},
                                                               sf::Vector2f{0.0, 5}, 5, false, false, window, state, audio });

                        coinList[0].setMoveSpeed(sf::Vector2f{ 0.0, 5 });
                    }
                    else {
                        coinList.push_back(PickUp{ manager, 2, sf::Vector2f{getRandomNumber(increaseValue + 600, increaseValue + 1200), 100},
                                       sf::Vector2f{0.03,0.03},
                                       sf::Vector2f{0.0, 5}, 5, false, false, window, state, audio });

                        coinList[0].setMoveSpeed(sf::Vector2f{ 0.0, 3 });
                    }


                    // On restart, delete all enemies further in the game and start over by placing one closeby.
                    if (enemyList.size() > 0) {
                        enemyList.pop_back();
                        enemyList.push_back(Enemy{ manager, 3, sf::Vector2f{getRandomNumber(1700, 1900), 100},
                                                               sf::Vector2f{2,2},
                                                               sf::Vector2f{0.0, 5}, 5, false, true, state, window, audio });
                        enemyList[0].setAnimationStates(&animationsMap["smallAlien"]);

                        animationsMap["smallAlien"].setState(PossibleStates::IDLE);

                        enemyList[0].setMoveSpeed(sf::Vector2f{ 0.0, 5 });
                    }
                    else {
                        enemyList.push_back(Enemy{ manager, 3, sf::Vector2f{getRandomNumber(1700, 1900), 100},
                                       sf::Vector2f{2,2},
                                       sf::Vector2f{0.0, 5}, 5, false, true, state, window, audio });
                        enemyList[0].setAnimationStates(&animationsMap["smallAlien"]);
                        animationsMap["smallAlien"].setState(PossibleStates::IDLE);

                        enemyList[0].setMoveSpeed(sf::Vector2f{ 0.0, 5 });
                    }

                    newCoinPosition = { 0.0,0.0 };
                    newEnemyPosition = { 0.0,0.0 };

                    player.resetScore();
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

        for (PickUp& current_object : coinList) {
            current_object.draw(window);
        }

        // Draw enemy.
        for (Enemy& current_object : enemyList) {
            current_object.draw(window);
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
 