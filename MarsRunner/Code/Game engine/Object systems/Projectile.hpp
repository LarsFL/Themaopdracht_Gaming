#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include "Code/Game engine/Physics systems/physics.hpp"
#include "Code/Game engine/Object systems/EnemyObject.hpp"

#include "GameObject.hpp"


class Projectile : public GameObject {
private:
public:
	Projectile(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocitySet) :
		GameObject(imageLocation, position, size, 5, false)
	{
		velocity = velocitySet;
	}

	bool update(std::deque<ObjectBlock>& objects, std::deque<Enemy>& enemies) {
		move(velocity);

		if (objectBlockHit(objects)) {
			return true;
		}

		if (gameObjectHit(enemies)) {
			return true;
		}

		return false;
	}

	bool objectBlockHit(std::deque<ObjectBlock>& objects) {
		for (auto& object : objects) {
			auto& thing = object.getObjects();
			for (auto& test : thing) {
				if (this->getGlobalBounds().intersects(test.second->getGlobalBounds())) {
					test.second->callLamba([&] {std::cout << "You've been hit"; });
					return true;
				}
			}
			//if (intersects(*this, object)) {
				//object.callLamba([&] {std::cout << "You've been hit"; });
				//return true;
			//}
		}
	}

	bool gameObjectHit(std::deque<Enemy>& enemies) {
		for (Enemy& current_enemy : enemies){
			if (this->getGlobalBounds().intersects(current_enemy.getGlobalBounds())) {
				std::cout << "Enemy dood";
				current_enemy.enemyKilled();
				return true;
			}
		}
	}
};



#endif //PROJECTILE_HPP