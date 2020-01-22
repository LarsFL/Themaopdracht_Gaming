#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <ctime>

#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"
#include "Code/Game engine/World Speed Systems/view.hpp"
#include "Code/Game engine/Object systems/Player.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML works!");

    sf::View mainView;
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

    std::string button = "../Assets/Test/grey_button01.png";
    std::string replaceButton = "../Assets/Test/green_button01.png";
    Button testButton{ button, replaceButton, sf::Vector2f { 0, 0}, sf::Vector2f{1,1.5 }, [&] {std::cout << "Test"; } };

    std::string fontLocation = "../Assets/Fonts/Mars.otf";
    std::string textext = "Hallo123";
    Text testText{ fontLocation, textext, sf::Vector2f{500,200}, sf::Vector2f{1,1}, [&] {std::cout << "Text clicc"; } };

    std::vector<UIElement*> UIElements = { &testButton, &testText };
    GameObject game_objects[] = { object };

    std::string testPlaatje = "../Assets/Test/testplaatje.png";

    GameObject ground{ testPlaatje, sf::Vector2f{100,250}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground1{ testPlaatje, sf::Vector2f{0,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground2{ testPlaatje, sf::Vector2f{82,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground3{ testPlaatje, sf::Vector2f{164,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground4{ testPlaatje, sf::Vector2f{246,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground5{ testPlaatje, sf::Vector2f{328,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground6{ testPlaatje, sf::Vector2f{410,400}, sf::Vector2f{0.1,0.1}, 5, false };
    GameObject ground7{ testPlaatje, sf::Vector2f{250,100}, sf::Vector2f{0.1,0.1}, 5, false };

    std::vector<GameObject*> groundObjects = { &ground, &ground1, &ground2 ,&ground3, &ground4, &ground5, &ground6, &ground7 };

    Player player{ testPlaatje, sf::Vector2f{0,250}, sf::Vector2f{0.1,0.1}, 5, false, window, groundObjects };
    player.setVelocity(sf::Vector2f{ 0.0, 1.1 });

    while (window.isOpen()) {

        unsigned int i = 0;
        auto previous = std::chrono::system_clock::now();
        auto lag = 0.0;
        float msPerLoop = 16.33;
        float minSpeed = 0.5;

        while (window.isOpen()) {
            // Always take the same time step per loop. (should work now)
            auto current = std::chrono::system_clock::now();
            std::chrono::duration<float, std::milli> elapsed = current - previous;
            previous = current;
            lag += elapsed.count();

            while (lag >= msPerLoop) {
                // Move the view at an ever increasing speed and move the background along with the same speed.
                update_view_position(mainView, window, minSpeed);
                float viewMoveSpeed = getViewMoveSpeed();
                move_object_with_view(background, viewMoveSpeed, minSpeed);

                // Check if selected object is within the bouns of the selected view
                sf::FloatRect view2 = getViewBounds(mainView);
                auto rect = object.getGlobalBounds();

                if (rect.intersects(view2)) {
                    //std::cout << "y\n";
                }
                else {
                    //std::cout << "n\n";
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

                player.update(minSpeed);

                lag -= msPerLoop;
            }

            window.clear();

            background.draw(window);

            for (auto& current_object : game_objects) {
                current_object.draw(window);
            }

            for (UIElement* current_object : UIElements) {
                current_object->draw(window);
            }

            for (auto& objectThing : groundObjects) {
                objectThing->draw(window);
            }

            player.draw(window);

            window.display();

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            i++;
        }

        return 0;
    }
}
