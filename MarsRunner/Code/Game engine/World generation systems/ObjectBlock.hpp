#ifndef _OBJECTBLOCK_HPP
#define _OBJECTBLOCK_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <array>
#include <iostream>
#include <memory>

#include "../Object systems/GameObject.hpp"
#include "../Object systems/WorldObject.hpp"

class ObjectBlock {
private:
	std::map<std::array<int, 2>, std::shared_ptr<WorldObject>> objects;
public:
	ObjectBlock() {};
	ObjectBlock(const ObjectBlock& r)
	{
		objects = r.objects;
		std::map<std::array<int, 2>, std::shared_ptr<WorldObject>>::iterator it;
		for (it = objects.begin(); it != objects.end(); it++) {
			it->second = std::make_shared<WorldObject>(*it->second);
		}
	}

	template<typename T>
	void addObject(sf::Vector2i position, T object);
	void draw(sf::RenderWindow& window);
	void remove() {};
	void setPositions(sf::Vector2f startPos, float width);
	sf::FloatRect getGlobalBounds();
};


#endif