#include "../Object systems/GameObject.hpp"
#include <iostream>

void updateVelocity(GameObject& obj) {
	obj.setVelocity(obj.getVelocity() + obj.getAcceleration());
}

bool intersects(GameObject& rhs, GameObject& lhs) {
	return rhs.getGlobalBounds().intersects(lhs.getGlobalBounds());
}

bool isObjOnGround(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left, globalBounds.top + globalBounds.height, globalBounds.width, 1);
	sf::FloatRect globalBoundsStatic = staticObj.getGlobalBounds();
	sf::FloatRect intersectionTesterStatic(globalBoundsStatic.left, globalBoundsStatic.top, globalBoundsStatic.width, movingObj.getVelocity().y + 20.0);
	return intersectionTester.intersects(intersectionTesterStatic);
}

bool isLeftIntersecting(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left - 2, globalBounds.top, 2, globalBounds.height - 6);
	return intersectionTester.intersects(staticObj.getGlobalBounds());
}

bool isRightIntersecting(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left + globalBounds.width, globalBounds.top, 2, globalBounds.height - 6);
	return intersectionTester.intersects(staticObj.getGlobalBounds());
}

bool isTopIntersecting(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left, globalBounds.top - 2, globalBounds.width, 2);
	return intersectionTester.intersects(staticObj.getGlobalBounds());
}