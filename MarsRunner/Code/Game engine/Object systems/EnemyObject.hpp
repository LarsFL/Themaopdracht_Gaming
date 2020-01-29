#ifndef _ENEMYOBJECT_HPP
#define _ENEMYOBJECT_HPP

#include "GameObject.hpp"

enum class enemyStates {
	IDLE,
	SHOOT,
	DEATH
};

class Enemy : public PickUp {
private:
	GameState& gameState;

public:
	Enemy(TextureManager manager, int textureID, sf::Vector2f position, sf::Vector2f size, sf::Vector2f moveSpeed, float weight, bool isStatic, bool animated, GameState& gameState, sf::RenderWindow& window) :
		PickUp(manager, textureID, position, size, moveSpeed, weight, isStatic, animated, window),
		gameState (gameState)
	{}

	Enemy(const Enemy& a) :
		PickUp(a.manager, a.textureID, a.position, a.size, a.moveSpeed, a.weight, a.isStatic, a.animated, a.window),
		gameState(a.gameState)
	{}

	void update() {

	}


	bool deathByEnemy(std::deque<Enemy>& list, Player& player, sf::View& view) {
		if (list.size() > 0) {
			sf::FloatRect itemBounds = list[0].getGlobalBounds();
			if (player.getGlobalBounds().intersects(itemBounds)) {
				std::cout << "You have been kiled1\n";
				
				player.setPlayerState(playerStates::DEATH);
				gameState.setState(game_states::GAME_OVER);

				return 1;
			}
			else {
				if (itemBounds.left + itemBounds.width < getViewBounds(view).left) {
					std::cout << "You have been kiled2\n";
					list.pop_back();
					return 1;
				}
			}
		}

		return 0;
	}
	
};

#endif