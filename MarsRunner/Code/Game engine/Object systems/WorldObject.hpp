#ifndef _WORLDOBJECT_HPP
#define _WORLDOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class WorldObject {
protected:

public:
	sf::Vector2f position = { 0, 0 };
	sf::Vector2f size = { 0, 0 };

	WorldObject(sf::Vector2f position_p, sf::Vector2f size_p) :
		position(position_p),
		size(size_p)
	{}

	WorldObject(const WorldObject& o) :
		position(o.position),
		size(o.size)
	{}

	WorldObject(WorldObject* o) :
		position(o->position),
		size(o->size)
	{}

	sf::FloatRect getGlobalBounds() {
		return sf::FloatRect(0,0,0,0);
	};
	void draw(sf::RenderWindow& window) { std::cout << "Wrong draw" << std::endl; };
	void setPosition(sf::Vector2f newPos) {};





	//virtual sf::Vector2f getVelocity();
	//virtual void setVelocity(sf::Vector2f newVelocity);
	//virtual sf::Vector2f getAcceleration();
};

#endif