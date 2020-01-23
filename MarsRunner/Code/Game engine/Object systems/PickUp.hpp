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

public:
	PickUp(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, float weight,
		bool isStatic, sf::RenderWindow& window) :

		GameObject(imageLocation, position, size, weight, isStatic),
		window(window)
	{}

	// Copy Constructor
	PickUp(const PickUp& a) :
		GameObject(a.imageLocation, a.position, a.size, a.weight, a.isStatic),
		window(a.window)
	{}

	void destroyObjectOnInteract(std::deque<PickUp> & list, std::string & coinImage, Player & player, float & increaseValue, sf::View & view) {
		sf::FloatRect itemBounds = list[0].getGlobalBounds();
		if (player.getGlobalBounds().intersects(itemBounds)) {
			// score ++, want hij pakt de coin.
			list.pop_back();
			list.push_back(PickUp{ coinImage, sf::Vector2f{getRandomNumber(increaseValue + 700, increaseValue + 1200), getRandomNumber(400, 500)}, sf::Vector2f{.05,.05}, 1, true, window });
		} else if (itemBounds.left + itemBounds.width < getViewBounds(view).left) {
			// niet score ++, want de coin gaat buiten het scherm
			list.pop_back();
			list.push_back(PickUp{ coinImage, sf::Vector2f{getRandomNumber(increaseValue + 700, increaseValue + 1200), getRandomNumber(400, 500)}, sf::Vector2f{.05,.05}, 1, true, window });
		}
	}
};

#endif //PICKUP_HPP