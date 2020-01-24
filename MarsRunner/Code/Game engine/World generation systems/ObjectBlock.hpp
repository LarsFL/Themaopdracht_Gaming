#ifndef _OBJECTBLOCK_HPP
#define _OBJECTBLOCK_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <array>
#include <iostream>
#include <memory>

#include "../Object systems/GameObject.hpp"
#include "../Tile systems/Tile.hpp"

class ObjectBlock {
private:
	std::map<std::array<int, 2>, std::shared_ptr<Tile>> objects;
public:
	ObjectBlock() {};
	ObjectBlock(const ObjectBlock& r)
	{
		objects = r.objects;
		std::map<std::array<int, 2>, std::shared_ptr<Tile>>::iterator it;
		for (it = objects.begin(); it != objects.end(); it++) {
			it->second = std::make_shared<Tile>(*it->second);
		}
	}

	void addObject(sf::Vector2i position, Tile& object);
	void draw(sf::RenderWindow& window);
	void remove() {};
	void setPositions(sf::Vector2f startPos, float width);
	sf::FloatRect getGlobalBounds();
};


#endif