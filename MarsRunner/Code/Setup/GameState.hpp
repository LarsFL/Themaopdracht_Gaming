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
	SAVE_SCORE,
	SCOREBOARD
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
	bool replay = false;
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

	void setReplay(bool newVal) {
		replay = newVal;
	}

	bool getReplay() {
		return replay;
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
			std::cout << "Sent score succesfully" << std::endl;
		}
	}

	void getLeaderboard() {
		sf::Http http("http://leaderboard.larsfl.com");
		sf::Http::Request request;
		request.setMethod(sf::Http::Request::Get);
		request.setUri("/index.php");
		sf::Http::Response response = http.sendRequest(request);

		std::stringstream ss(response.getBody());
		std::string to;
		std::string substr;
		bool name = true;
		unsigned int i = 1;
		while (std::getline(ss, to, '\n') && i <= 10) {
			std::stringstream str(to);
			while (std::getline(str, substr, ',')) {
				if (name) {
					std::string name = "Score" + std::to_string(i) + "Name";
					updateUIElement(game_states::SCOREBOARD, name, substr);
				}
				else {
					std::string score = "Score" + std::to_string(i) + "Value";
					updateUIElement(game_states::SCOREBOARD, score, substr);
				}
				name = !name;
			}
			i++;
		}
	}


};

#endif