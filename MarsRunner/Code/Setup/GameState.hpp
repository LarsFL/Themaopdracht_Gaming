#ifndef _GAMESTATE_HPP
#define _GAMESTATE_HPP

#include <map>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <sstream>

#include "Code/Game engine/UI systems/UI_State.hpp"

enum class game_states {
	MAIN_MENU,
	GAME_OVER,
	PAUSED,
	PLAYING,
	SAVE_SCORE
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
	bool enterText = false;
	sf::String enteredText = "";
public:
	bool closeGame = false;
	GameState() {}

	void addUIState(game_states newState, UI_State &stateUI) {
		UIStates[newState] = new UI_State(stateUI);
	}

	void updateUIElement(game_states state, std::string identifier, std::string newValue) {
		UIStates[state]->updateUIElement(identifier, newValue);
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

	game_states getState() {
		return state;
	}

	bool getEnterText() {
		return enterText;
	}

	void setEnterText() {
		std::cout << enterText;
		if (enterText == false) {
			enteredText = "Name";
		}
		enterText = !enterText;
	}

	sf::String getText() {
		return enteredText;
	}

	void setEnteredString(sf::String& text) {
		enteredText = text;
	}

	uint32_t getScore() {
		return score;
	}

	void setScore(uint32_t newScore) {
		score = newScore;
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

	void sendScore(sf::String name, int score) {
		sf::Http::Request request("/post.php", sf::Http::Request::Post);
		std::ostringstream stream;
		stream << "name=" << name.toAnsiString() << "&score=" << score;
		request.setBody(stream.str());
		sf::Http http("http://leaderboard.larsfl.com/");
		sf::Http::Response response = http.sendRequest(request);
		if (response.getStatus() == sf::Http::Response::Ok) {
			std::cout << "Send succesfully" << std::endl;
		}
	}


};

#endif