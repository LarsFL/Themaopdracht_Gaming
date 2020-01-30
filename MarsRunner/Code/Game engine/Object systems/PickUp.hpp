#ifndef PICKUP_HPP
#define PICKUP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <deque>

#include "Code/Game engine/Object systems/GameObject.hpp"
#include "Code/Game engine/Audio systems/AudioManager.hpp"
#include "Code/Setup/GameState.hpp"

class PickUp : public GameObject {
protected:
	sf::RenderWindow& window;
	sf::Vector2f moveSpeed = { 0,0 };
	GameState& state;
	AudioManager& audio;

public:
	PickUp(TextureManager manager, int textureID, sf::Vector2f position, sf::Vector2f size, sf::Vector2f moveSpeed, float weight,
		bool isStatic, bool animated, sf::RenderWindow& window, GameState& state, AudioManager& audio) :

		GameObject(manager, textureID, position, size, weight, isStatic, animated),
		moveSpeed(moveSpeed),
		window(window),
		state(state),
		audio(audio)
	{
		//std::cout << "value: " << position.x << "\n";
	}

	// Copy Constructor
	PickUp(const PickUp& a) :
		GameObject(a.manager, a.textureID, a.position, a.size, a.weight, a.isStatic, a.animated),
		moveSpeed(a.moveSpeed),
		window(a.window),
		state(a.state),
		audio(a.audio)
	{}

	sf::Vector2f getMoveSpeed() {
		return moveSpeed;
	}

	void setMoveSpeed(sf::Vector2f newSpeed) {
		this->moveSpeed = newSpeed;
	}

	bool destroyObjectOnInteract(std::deque<PickUp>& list, sf::FloatRect playerRect, sf::View& view) {
		if (list.size() > 0) {
			sf::FloatRect itemBounds = list[0].getGlobalBounds();
			if (playerRect.intersects(itemBounds)) {
				audio.playSound("coin");
				std::cout << state.getScore() << std::endl;
				state.setScore(state.getScore() + 250);
				list.pop_back();
				return 1;
			}
			else {
				if (itemBounds.left + itemBounds.width < getViewBounds(view).left) {
					list.pop_back();
					return 1;
				}
			}
		}

		return 0;
	}
};

#endif //PICKUP_HPP