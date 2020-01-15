#ifndef _GAMESTATE_HPP
#define _GAMESTATE_HPP

#include <map>
#include <string>

#include "Code/Game engine/UI systems/UI_State.hpp"

enum game_states {
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


	void addUIState(game_states state, UI_State* stateUI) {
		UIStates[state] = stateUI;
	}

	void draw(sf::RenderWindow& window) {
		UIStates[state]->draw(window);
	}


};

#endif