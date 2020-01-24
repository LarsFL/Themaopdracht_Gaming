#ifndef PICKUP_HPP
#define PICKUP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <deque>

#include "GameObject.hpp"
#include "Player.hpp"
//#include "../Tile systems/TextureManager.hpp"
//#include "../Tile systems/Texture.hpp"

class PickUp : public GameObject {
protected:
	sf::RenderWindow& window;

public:
	PickUp(TextureManager manager, int textureID, sf::Vector2f position, sf::Vector2f size, float weight,
		bool isStatic, bool animated, sf::RenderWindow& window) :

		GameObject(manager, textureID, position, size, weight, isStatic, animated),
		window(window)
	{}

	// Copy Constructor
	PickUp(const PickUp& a) :
		GameObject(a.manager, a.textureID, a.position, a.size, a.weight, a.isStatic, a.animated),
		window(a.window)
	{}

	void setPickUpTexture(std::string & path) {
		Texture itemTexture{ path };
		manager.addTexture(1, itemTexture);
	}

	//void destroyObjectOnInteract(std::deque<PickUp> & list, std::string & coinImage, Player & player, float & increaseValue, sf::View & view) {
	void destroyObjectOnInteract(std::deque<PickUp> & list, TextureManager & manager, float& increaseValue, sf::View & view){
		sf::FloatRect itemBounds = list[0].getGlobalBounds();
		//if (player.getGlobalBounds().intersects(itemBounds)) {
		//	// score ++, want hij pakt de coin.
		//	list.pop_back();
		//	list.push_back(PickUp{ coinImage, sf::Vector2f{getRandomNumber(increaseValue + 700, increaseValue + 1200), getRandomNumber(400, 500)}, sf::Vector2f{.05,.05}, 1, true, window });
		//} else 
		if (itemBounds.left + itemBounds.width < getViewBounds(view).left) {
			// niet score ++, want de coin gaat buiten het scherm
			std::cout << "Yeet\n";
			list.pop_back();
			list.push_back(PickUp{ manager, 0, sf::Vector2f{getRandomNumber(increaseValue + 700, increaseValue + 1200), getRandomNumber(400, 500)}, 
									sf::Vector2f{.05,.05}, 1, true, false, window });
		}
	}
};

#endif //PICKUP_HPP