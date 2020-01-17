#ifndef _INITIALIZEUI_HPP
#define _INITIALIZEUI_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Code/Game engine/UI systems/UI_State.hpp"
#include "Code/Game engine/UI systems/UI_State.hpp"
#include "Code/Game engine/UI systems/Button.hpp"
#include "Code/Game engine/UI systems/Text.hpp"

#include "Code/Setup/GameState.hpp"

void InitializeUI(sf::RenderWindow& window, sf::View & fixedView, GameState & state) {
	auto screenSize = fixedView.getSize();
	std::string fontLocation = "../Assets/Fonts/Mars.otf";
	std::string notClickButton =	"../Assets/Test/grey_button01.png";
	std::string clickButton =		"../Assets/Test/green_button01.png";
	std::string emptyText = "";


	/*
		Initialization of Main Menu
	*/

	UI_State mainMenuState("Main Menu");

	// Title text
	std::string titleText = "Mars Runner";
	Text TitleText{ fontLocation, titleText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 100 };
	TitleText.centerOrigin();
	TitleText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 2.3f))));
	mainMenuState.append(TitleText);

	// Play button
	Button PlayButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "CLICC" << std::endl; state.setState(game_states::PLAYING); } };
	PlayButton.centerOrigin();
	PlayButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 7))));
	mainMenuState.append(PlayButton);

	std::string playButtonText = "Play";
	Text PlayText{ fontLocation, playButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	PlayText.centerOrigin();
	PlayText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 6.2f))));
	mainMenuState.append(PlayText);

	// Leaderboard button
	Button LeaderboardButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Leaderboard clicc" << std::endl; } };
	LeaderboardButton.centerOrigin();
	LeaderboardButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2)));
	mainMenuState.append(LeaderboardButton);

	std::string leaderboardButtonText = "Leaderboard";
	Text LeaderboardText{ fontLocation, leaderboardButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	LeaderboardText.centerOrigin();
	LeaderboardText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 50))));
	mainMenuState.append(LeaderboardText);

	// Quit button
	Button QuitButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Quit clicc" << std::endl; } };
	QuitButton.centerOrigin();
	QuitButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 7))));
	mainMenuState.append(QuitButton);

	std::string quitButtonText = "Quit";
	Text QuitText{ fontLocation, quitButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	QuitText.centerOrigin();
	QuitText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 8.2f))));
	mainMenuState.append(QuitText);
	
	// Add state to UI states
	state.addUIState(game_states::MAIN_MENU, mainMenuState);
	
	/*
		Initialization of Playing UI
	*/

	UI_State playingState("Playing");

	// Score text
	std::string scoreText = "Score. ";
	Text ScoreText{ fontLocation, scoreText, sf::Vector2f(20,20), sf::Vector2f(1,1), [&] {}, 30 };
	playingState.append(ScoreText);


	std::string tmpScore = "12345";
	Text ScoreValueText{ fontLocation, tmpScore, sf::Vector2f(85, 20), sf::Vector2f(1,1), [&] {}, 30 };
	playingState.append(ScoreValueText);

	// Add state to UI states
	state.addUIState(game_states::PLAYING, playingState);
}

#endif