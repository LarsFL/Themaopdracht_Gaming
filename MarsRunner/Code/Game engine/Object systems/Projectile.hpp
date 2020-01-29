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
			for (auto& item : thing) {
				if (this->getGlobalBounds().intersects(item.second->getGlobalBounds())) {
					return true;
				}
			}
		}

		return false;
	}

	bool gameObjectHit(std::deque<Enemy>& enemies) {
		for (Enemy& current_enemy : enemies){
			if (this->getGlobalBounds().intersects(current_enemy.getGlobalBounds())) {
				current_enemy.enemyKilled();
				return true;
			}
		}

		return false;
	}
};



#endif //PROJECTILE_HPP