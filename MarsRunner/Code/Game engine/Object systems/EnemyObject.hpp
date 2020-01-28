#ifndef _ENEMYOBJECT_HPP
#define _ENEMYOBJECT_HPP

#include "GameObject.hpp"

enum class enemyStates {
	IDLE,
	SHOOT,
	DEATH
};

class Enemy : public GameObject {
private:


public:
	Enemy(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, float weight, bool isStatic, bool animated) :
		GameObject(imageLocation, position, size, weight, isStatic, animated)
	{}

	Enemy(const Enemy& a) :
		GameObject(a.imageLocation, a.position, a.size, a.weight, a.isStatic, a.animated)
	{}

	void update() {

	}
};

#endif