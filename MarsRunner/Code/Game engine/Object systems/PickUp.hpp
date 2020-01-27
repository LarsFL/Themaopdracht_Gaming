#ifndef PICKUP_HPP
#define PICKUP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <deque>

class PickUp : public WorldObject {
private:

public:
	PickUp(sf::Vector2f position, sf::Vector2f size) :
		WorldObject(position, size)
	{}

	// Copy Constructor
	PickUp(const PickUp& a) :
		WorldObject(a.position, a.size)
	{}

	bool destroyObjectOnInteract(sf::View & view, WorldObject & wObject){
		sf::FloatRect itemBounds = this->getGlobalBounds();
		//if (player.getGlobalBounds().intersects(itemBounds)) {
		//	std::cout << "y\n";
		//	//list.pop_back();
		//	return 1;
		//} else 
			if (itemBounds.left + itemBounds.width < getViewBounds(view).left) {
			std::cout << "n\n";
			//list.pop_back();
			return 1;
		}

		return 0;
	}	
};

#endif //PICKUP_HPP