#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include "Code/Game engine/Physics systems/physics.hpp"

#include "GameObject.hpp"


class Projectile : public GameObject {
private:
public:
	Projectile(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocitySet) :
		GameObject(imageLocation, position, size, 5, false)
	{
		velocity = velocitySet;
	}

	bool update(std::deque<GameObject>& objects) {
		move(velocity);
		for (auto& object : objects) {
			if (intersects(*this, object)) {
				object.callLamba([&] {std::cout << "You've been hit"; });
				return true;
			}
		}
		return false;
	}
};



#endif //PROJECTILE_HPP