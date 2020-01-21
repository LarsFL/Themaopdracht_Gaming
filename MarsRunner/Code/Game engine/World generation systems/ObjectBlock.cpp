#include <SFML/Graphics.hpp>
#include <map>

#include "ObjectBlock.hpp"

void ObjectBlock::addObject(sf::Vector2i position, GameObject object) {
	objects[{position.x, position.y}] = object;
}

void ObjectBlock::draw(sf::RenderWindow& window) {
	std::map<std::array<int, 2>, GameObject>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
		it->second.draw(window);
	}
}

void ObjectBlock::setPositions(sf::Vector2f startPos, float width) {
	std::map<std::array<int, 2>, GameObject>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
		auto pos = it->first;
		it->second.jump(sf::Vector2f((startPos.x + (pos[0] * width)), pos[1] * width));
	}
}

sf::FloatRect ObjectBlock::getGlobalBounds() {
	int biggest = -5;
	GameObject* highest = nullptr;
	std::map<std::array<int, 2>, GameObject>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
		if (it->first[0] > biggest) {
			biggest = it->first[0];
			highest = &it->second;
		}
	}
	if (highest != nullptr) {
		return highest->getGlobalBounds();
	}
}