#ifndef PICKUP_HPP
#define PICKUP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <deque>

#include "GameObject.hpp"
#include "Player.hpp"

class PickUp : public GameObject {
protected:
	sf::RenderWindow& window;
	sf::Vector2f moveSpeed = { 0,0 };

public:
	PickUp(TextureManager manager, int textureID, sf::Vector2f position, sf::Vector2f size, sf::Vector2f moveSpeed, float weight,
		bool isStatic, bool animated, sf::RenderWindow& window) :

		GameObject(manager, textureID, position, size, weight, isStatic, animated),
		moveSpeed(moveSpeed),
		window(window)
	{}

	// Copy Constructor
	PickUp(const PickUp& a) :
		GameObject(a.manager, a.textureID, a.position, a.size, a.weight, a.isStatic, a.animated),
		moveSpeed(a.moveSpeed),
		window(a.window)
	{}

	sf::Vector2f getMoveSpeed() {
		return moveSpeed;
	}

	void setMoveSpeed(sf::Vector2f newSpeed) {
		this->moveSpeed = newSpeed;
	}
	
	bool destroyObjectOnInteract(std::deque<PickUp> & list, Player & player, sf::View & view){
		sf::FloatRect itemBounds = list[0].getGlobalBounds();
		if (player.getGlobalBounds().intersects(itemBounds)) {
			list.pop_back();
			std::cout << "y\n";
			return 1;
		} else 
		if (itemBounds.left + itemBounds.width < getViewBounds(view).left) {
			list.pop_back();
			std::cout << "n\n";
			return 1;
		}

		return 0;
	}
};

#endif //PICKUP_HPP