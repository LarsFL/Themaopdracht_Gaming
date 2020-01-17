#ifndef _GAMESTATE_HPP
#define _GAMESTATE_HPP

#include <map>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Code/Game engine/UI systems/UI_State.hpp"

enum class game_states {
	MAIN_MENU,
	GAME_OVER,
	PAUSED,
	PLAYING
};

enum class paused_substates {
	MAIN,
	ARE_YOU_SURE
};

class GameState {
private:
	std::map<game_states, UI_State*> UIStates = {};
	uint32_t score = 0;
	uint16_t enemiesSlain = 0;
	std::string playerName = "Elon";
	game_states state = game_states::MAIN_MENU;
public:
	bool closeGame = false;
	GameState() {}

	void addUIState(game_states newState, UI_State &stateUI) {
		auto copyUI(stateUI);
		UIStates[newState] = new UI_State(stateUI);
	}

	void draw(sf::RenderWindow& window) {
		UIStates[state]->draw(window);
	}

	void updateUI(sf::Vector2f& mouse_pos) {
		UIStates[state]->update(mouse_pos);
	}

	void setState(game_states newState) {
		state = newState;
	}

	void handleEscape() {
		switch (state) {
			case (game_states::MAIN_MENU): {
				closeGame = true;
				return;
			}
			case (game_states::PLAYING): {
				state = game_states::PAUSED;
				return;
			}
			case (game_states::PAUSED): {
				state = game_states::PLAYING;
				return;
			}
		}
	}


};

#endif