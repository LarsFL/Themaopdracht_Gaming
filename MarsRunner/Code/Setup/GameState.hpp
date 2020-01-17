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

class GameState {
private:
	std::map<game_states, UI_State*> UIStates = {};
	uint32_t score = 0;
	uint16_t enemiesSlain = 0;
	std::string playerName = "Elon";
	game_states state = game_states::MAIN_MENU;
public:
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


};

#endif