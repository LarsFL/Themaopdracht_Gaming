#ifndef _OBJECTBLOCK_HPP
#define _OBJECTBLOCK_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <array>

#include "../Object systems/GameObject.hpp"

class ObjectBlock {
private:
	std::map<std::array<int, 2>, GameObject> objects;
public:
	ObjectBlock() {};
	ObjectBlock(const ObjectBlock& r) :
		objects(r.objects)
	{}

	void addObject(sf::Vector2i position, GameObject object);
	void draw(sf::RenderWindow& window);
	void remove() {};
	void setPositions(sf::Vector2f startPos, float width);
	sf::FloatRect getGlobalBounds();
};


#endif