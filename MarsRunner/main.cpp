#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>

#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"

void move_background_with_view(GameObject & object, double & amount) {
    /// Move the background at the ame speed as the view.    
    double minSpeed = 0.05;

    if ((amount) < minSpeed) {
        object.move(sf::Vector2f{ ((float)minSpeed), 0 });
    }
    else {
        object.move(sf::Vector2f{ ((float)amount), 0 });
    }
}

void update_game_object_speed(GameObject & object) {
    /// Move all object from the game object array in a constant motion.
    object.move(sf::Vector2f{ 0.1, 0.1 });
}

double update_view_position(sf::View & view, sf::RenderWindow & window, double amount) {
    /// Move the selected view in a slowly accelerating motion.
    double minSpeed = 0.05;
    static double increaseValue = minSpeed;
    increaseValue += amount;

    // Move the view with a constant speed, until a certain value. From there the speed will slowly increase.
    if ((increaseValue / 500) < minSpeed) {
        view.move(minSpeed, 0);
    } else {
        view.move(increaseValue / 500, 0);
    }
    
    window.setView(view);
    return increaseValue / 500;
}

sf::FloatRect getViewBounds(const sf::View & view){
    /// Return the bound of the selected view.
    sf::FloatRect rt;
    rt.left = view.getCenter().x - view.getSize().x / 2.f;
    rt.top = view.getCenter().y - view.getSize().y / 2.f;
    rt.width = view.getSize().x;
    rt.height = view.getSize().y;
    return rt;
}

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
    
    std::string thing = "../Assets/Test/testplaatje.png";
    GameObject object{ thing, sf::Vector2f{1200, 500}, sf::Vector2f{0.1, 0.1}, 5, false };

    std::string path = "../Assets/Test/background2.png";
    GameObject background{ path, sf::Vector2f{-250, -250}, sf::Vector2f{1.2, 1.4}, 5, false };

    GameObject game_objects[] = { object };

    action actions[] = {
        action(sf::Keyboard::Up,    [&]() { mainView.move(0, -1); window.setView(mainView); }),
        action(sf::Keyboard::Left,  [&]() { mainView.move(-1, 0); window.setView(mainView); }),
        action(sf::Keyboard::Down,  [&]() { mainView.move(0, 1); window.setView(mainView); }),
        action(sf::Keyboard::Right, [&]() { mainView.move(1, 0); window.setView(mainView); }),

        action(sf::Keyboard::W,     [&]() { std::cout << "W\n"; }),
        action(sf::Keyboard::A,     [&]() { std::cout << "A\n"; }),
        action(sf::Keyboard::S,     [&]() { std::cout << "S\n"; }),
        action(sf::Keyboard::D,     [&]() { std::cout << "D\n"; }),

        action(sf::Keyboard::Space, [&]() { std::cout << "Space\n"; }),

        action(sf::Mouse::Left,     [&]() { std::cout << "Mouse\n"; })
    };

    auto previous = std::chrono::system_clock::now();
    auto lag = 0.0;

    while (window.isOpen()){
        // Always take the same time step per loop. (should work)
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = current - previous;
        previous = current;
        lag += elapsed.count();

        for (auto& action : actions){
            action();
        }

        while (lag >= elapsed.count()){
            // Move the view at an ever increasing speed and move the background along with the same speed.
            double viewMoveSpeed = update_view_position(mainView, window, elapsed.count());
            move_background_with_view(background, viewMoveSpeed);

            // Check if selected object is within the bouns of the selected view
            sf::FloatRect view2 = getViewBounds(mainView);
            auto rect = object.getGlobalBounds();

            if (rect.intersects(view2)){
                //std::cout << "y\n";
            }
            else {
                //std::cout << "n\n";
            }

            

            /* Zet hier je code. */
            



            lag -= elapsed.count();
        }

        window.clear();

        background.draw(window);

        for (auto & current_object : game_objects){
            current_object.draw(window);
        }
        window.draw(shape);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    }
        
    return 0;
}

