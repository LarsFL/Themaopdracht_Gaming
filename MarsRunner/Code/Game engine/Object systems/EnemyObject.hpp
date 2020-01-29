#ifndef _ENEMYOBJECT_HPP
#define _ENEMYOBJECT_HPP

#include <deque>

#include "Code/Game engine/Object systems/PickUp.hpp"
#include "Code/Game engine/Object systems/Player.hpp"
#include "Code/Setup/GameState.hpp"

enum class enemyStates {
	IDLE,
	SHOOT,
	DEATH
};

class Enemy : public PickUp {
private:
	GameState& gameState;
	enemyStates thisState = enemyStates::IDLE;

public:
	Enemy(TextureManager manager, int textureID, sf::Vector2f position, sf::Vector2f size, sf::Vector2f moveSpeed, float weight, bool isStatic, bool animated, GameState& gameState, sf::RenderWindow& window) :
		PickUp(manager, textureID, position, size, moveSpeed, weight, isStatic, animated, window),
		gameState(gameState)
	{}

	Enemy(const Enemy& a) :
		PickUp(a.manager, a.textureID, a.position, a.size, a.moveSpeed, a.weight, a.isStatic, a.animated, a.window),
		gameState(a.gameState)
	{}
	
	bool enemyOutOfBounds(std::deque<Enemy>& list, sf::View& view) {
		if (list.size() > 0) {
		sf::FloatRect itemBounds = list[0].getGlobalBounds();
			if (itemBounds.left + itemBounds.width < getViewBounds(view).left) {
				std::cout << "You have been kiled2\n";
				list.pop_back();
				return 1;
			}
		}

		return 0;
	}

	void enemyKilled() {
		std::cout << "enemy doood!!!!!!!";
		thisState = enemyStates::DEATH;
		animations->setState(PossibleStates::DEATH);
	}

	enemyStates getState() {
		return thisState;
	}

	void setState(enemyStates newState) {
		thisState = newState;
	}
};

#endif