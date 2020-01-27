#include <SFML/Graphics.hpp>
#include <map>

#include "ObjectBlock.hpp"

#include "../Object systems/GameObject.hpp"
#include "../Object systems/WorldObject.hpp"

template<typename T>
void ObjectBlock::addObject(sf::Vector2i position, T object) {
	objects[{position.x, position.y}] = std::make_shared<T>(object);
}

void ObjectBlock::draw(sf::RenderWindow& window) {
	std::map<std::array<int, 2>, std::shared_ptr<WorldObject>>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
		it->second->draw(window);
	}
}

void ObjectBlock::setPositions(sf::Vector2f startPos, float width) {
	std::map<std::array<int, 2>, std::shared_ptr<WorldObject>>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
		auto pos = it->first;
		it->second->setPosition(sf::Vector2f((startPos.x + (pos[0] * width)), pos[1] * width));
	}
}

std::vector<sf::FloatRect> ObjectBlock::getGlobalBoundsFromTiles() {

	/*int biggest = -5;
	std::shared_ptr<WorldObject> highest = nullptr;
	std::map<std::array<int, 2>, std::shared_ptr<WorldObject>>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
		if (it->first[0] > biggest) {
			biggest = it->first[0];
			highest = it->second;
		}
	}
	if (highest != nullptr) {
		return highest->getGlobalBounds();
	}*/

	std::vector<sf::FloatRect> GB;
	for (auto& object : objects) {
		GB.push_back(object.second->getGlobalBounds());
	}
	return GB;
}

sf::FloatRect ObjectBlock::getGlobalBounds() {
	int biggest = -5;
	std::shared_ptr<WorldObject> highest = nullptr;
	std::map<std::array<int, 2>, std::shared_ptr<WorldObject>>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++) {
		if (it->first[0] > biggest) {
			biggest = it->first[0];
			highest = it->second;
		}
	}
	if (highest != nullptr) {
		return highest->getGlobalBounds();
	}
}