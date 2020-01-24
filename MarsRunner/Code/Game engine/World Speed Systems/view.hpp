#ifndef VIEW_HPP
#define VIEW_HPP

#include <SFML/Graphics.hpp>

static float speedCalculatedByFunction = 0.0;

void move_object_with_view(GameObject& object, float& amount, float& minSpeed) {
    /// Move the background at the ame speed as the view.    
    if (amount < minSpeed) {
        object.move(sf::Vector2f{ minSpeed, 0 });
    } else {
        object.move(sf::Vector2f{ amount, 0 });
    }
}

void update_game_object_speed(GameObject& object) {
    /// Move all object from the game object array in a constant motion.
    object.move(sf::Vector2f{ 0.1, 0.1 });
}

void update_view_position(sf::View& view, sf::RenderWindow& window, float & minSpeed) {
    /// Move the selected view in a slowly accelerating motion.
    float devideValue = 5000.0;
    static float increaseValue = minSpeed;
    increaseValue += 2;

    // Move the view with a constant speed, until a certain value. From there the speed will slowly increase.
    if ((increaseValue / devideValue) < minSpeed) {
        view.move(minSpeed, 0);
    } else {
        view.move(increaseValue / devideValue, 0);
    }
    window.setView(view);
    speedCalculatedByFunction = increaseValue / devideValue;
}

float getViewMoveSpeed() {
    return speedCalculatedByFunction;
}

sf::FloatRect getViewBounds(const sf::View& view) {
    /// Return the bound of the selected view.
    sf::FloatRect rt;
    rt.left = view.getCenter().x - view.getSize().x / 2.f;
    rt.top = view.getCenter().y - view.getSize().y / 2.f;
    rt.width = view.getSize().x;
    rt.height = view.getSize().y;
    return rt;
}

#endif // VIEW_HPP
