#include "../World generation systems/ObjectBlock.hpp"
#include <iostream>

void updateVelocity(GameObject& obj) {
	obj.setVelocity(obj.getVelocity() + obj.getAcceleration());
}

//bool intersects(GameObject& rhs, GameObject& lhs) {
//	return rhs.getGlobalBounds().intersects(lhs.getGlobalBounds());
//}

bool isObjOnGround(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left, globalBounds.top + globalBounds.height, globalBounds.width, 1);
	sf::FloatRect globalBoundsStatic = staticObj.getGlobalBounds();
	sf::FloatRect intersectionTesterStatic(globalBoundsStatic.left, globalBoundsStatic.top, globalBoundsStatic.width, movingObj.getVelocity().y + 20.0);
	return intersectionTester.intersects(intersectionTesterStatic);
}

bool isLeftIntersecting(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left - 2, globalBounds.top, 2, globalBounds.height - 10);
	return intersectionTester.intersects(staticObj.getGlobalBounds());
}

bool isRightIntersecting(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left + globalBounds.width, globalBounds.top, 2, globalBounds.height - 10);
	return intersectionTester.intersects(staticObj.getGlobalBounds());
}

bool isTopIntersecting(GameObject& movingObj, GameObject& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left, globalBounds.top - 2, globalBounds.width, 2);
	return intersectionTester.intersects(staticObj.getGlobalBounds());
}

//bool intersects(GameObject& rhs, ObjectBlock& lhs) {
//	return rhs.getGlobalBounds().intersects(lhs.getGlobalBounds());
//}

bool isObjOnGround(GameObject& movingObj, ObjectBlock& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left, globalBounds.top + globalBounds.height, globalBounds.width, 1);
	
	std::vector<sf::FloatRect> GB = staticObj.getGlobalBoundsFromTiles();
	for (auto& object : GB) {
		sf::FloatRect intersectionTesterStatic(object.left - 2, object.top, object.width + 2, movingObj.getVelocity().y + 20.0);
		if (intersectionTester.intersects(intersectionTesterStatic)) {
			return true;
		}
	}
	return false;
}

bool isLeftIntersecting(GameObject& movingObj, ObjectBlock& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left - 2, globalBounds.top + 15, 2, globalBounds.height - 40);

	std::vector<sf::FloatRect> GB = staticObj.getGlobalBoundsFromTiles();
	for (auto& object : GB) {
		if (intersectionTester.intersects(object)) {
			return true;
		}
	}
	return false;
}

bool isRightIntersecting(GameObject& movingObj, ObjectBlock& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left + globalBounds.width + 15, globalBounds.top, 2, globalBounds.height - 40);

	std::vector<sf::FloatRect> GB = staticObj.getGlobalBoundsFromTiles();
	for (auto& object : GB) {
		if (intersectionTester.intersects(object)) {
			return true;
		}
	}
	return false;
}

bool isTopIntersecting(GameObject& movingObj, ObjectBlock& staticObj) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left, globalBounds.top - 2, globalBounds.width, 2);

	std::vector<sf::FloatRect> GB = staticObj.getGlobalBoundsFromTiles();
	for (auto& object : GB) {
		if (intersectionTester.intersects(object)) {
			return true;
		}
	}
	return false;
}

bool isRightIntersecting(GameObject& movingObj, sf::FloatRect viewBounds) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left + globalBounds.width + 15, globalBounds.top, 2, globalBounds.height - 40);

	sf::FloatRect intersectionTesterView(viewBounds.left + viewBounds.width, viewBounds.top, 20, viewBounds.height);
	return intersectionTester.intersects(intersectionTesterView);
}

bool isLeftIntersecting(GameObject& movingObj, sf::FloatRect viewBounds) {
	sf::FloatRect globalBounds = movingObj.getGlobalBounds();
	sf::FloatRect intersectionTester(globalBounds.left + globalBounds.width + 15, globalBounds.top, 2, globalBounds.height - 40);

	sf::FloatRect intersectionTesterView(viewBounds.left, viewBounds.top, 20, viewBounds.height);
	return intersectionTester.intersects(intersectionTesterView);
}