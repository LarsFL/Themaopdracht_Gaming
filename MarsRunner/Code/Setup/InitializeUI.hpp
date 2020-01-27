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
	mainMenuState.append("TitleText", TitleText);

	// Play button
	Button PlayButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "CLICC" << std::endl; state.setState(game_states::PLAYING); } };
	PlayButton.centerOrigin();
	PlayButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 7))));
	mainMenuState.append("PlayButton", PlayButton);

	std::string playButtonText = "Play";
	Text PlayText{ fontLocation, playButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	PlayText.centerOrigin();
	PlayText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 6.2f))));
	mainMenuState.append("PlayText", PlayText);

	// Leaderboard button
	Button LeaderboardButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Leaderboard clicc" << std::endl; } };
	LeaderboardButton.centerOrigin();
	LeaderboardButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2)));
	mainMenuState.append("LeaderboardButton", LeaderboardButton);

	std::string leaderboardButtonText = "Leaderboard";
	Text LeaderboardText{ fontLocation, leaderboardButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	LeaderboardText.centerOrigin();
	LeaderboardText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 50))));
	mainMenuState.append("LeaderboardText", LeaderboardText);

	// Quit button
	Button QuitButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Quit clicc" << std::endl; /*state.closeGame = true;*/ } };
	QuitButton.centerOrigin();
	QuitButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 7))));
	mainMenuState.append("QuitButton", QuitButton);

	std::string quitButtonText = "Quit";
	Text QuitText{ fontLocation, quitButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	QuitText.centerOrigin();
	QuitText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 8.2f))));
	mainMenuState.append("QuitButtonText", QuitText);
	
	// Add state to UI states
	state.addUIState(game_states::MAIN_MENU, mainMenuState);
	
	/*
		Initialization of Playing UI
	*/

	UI_State playingState("Playing");

	// Score text
	std::string scoreText = "Score. ";
	Text ScoreText{ fontLocation, scoreText, sf::Vector2f(20,20), sf::Vector2f(1,1), [&] {}, 30 };
	playingState.append("ScoreText", ScoreText);


	std::string tmpScore = "12345";
	Text ScoreValueText{ fontLocation, tmpScore, sf::Vector2f(85, 20), sf::Vector2f(1,1), [&] {}, 30 };
	playingState.append("ScoreValueText", ScoreValueText);

	// Add state to UI states
	state.addUIState(game_states::PLAYING, playingState);


	/*
		Initialization of Paused UI
	*/

	UI_State pausedState("Paused");

	// Paused text
	std::string pausedText = "Paused";
	Text PausedText{ fontLocation, pausedText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 100 };
	PausedText.centerOrigin();
	PausedText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 2.3f))));
	pausedState.append("PausedText", PausedText);


	// Score text
	Text PausedScoreText{ fontLocation, scoreText, sf::Vector2f(20,20), sf::Vector2f(1,1), [&] {}, 50 };
	PausedScoreText.jump(sf::Vector2f((screenSize.x / 2) - 100, (screenSize.y / 2 - (screenSize.y / 6.2f))));
	pausedState.append("PausedScoreText", PausedScoreText);

	Text PausedScoreValueText{ fontLocation, tmpScore, sf::Vector2f(85, 20), sf::Vector2f(1,1), [&] {}, 30 };
	PausedScoreValueText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 6.2f) + 18)));
	pausedState.append("PausedScoreValueText", PausedScoreValueText);

	// Resume button
	Button ResumeButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Resume clicc" << std::endl; state.setState(game_states::PLAYING); } };
	ResumeButton.centerOrigin();
	ResumeButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2)));
	pausedState.append("ResumeButton", ResumeButton);

	std::string resumeButtonText = "Resume";
	Text ResumeButtonText{ fontLocation, resumeButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	ResumeButtonText.centerOrigin();
	ResumeButtonText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 50))));
	pausedState.append("ResumeButtonText", ResumeButtonText);

	// Back to menu button
	Button BackToMenuButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Back to menu clicc" << std::endl; state.setState(game_states::MAIN_MENU); } };
	BackToMenuButton.centerOrigin();
	BackToMenuButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 7))));
	pausedState.append("BackToMenuButton", BackToMenuButton);

	std::string backToMenuButtonText = "Back to menu";
	Text BackToMenuButtonText{ fontLocation, backToMenuButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	BackToMenuButtonText.centerOrigin();
	BackToMenuButtonText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 8.2f))));
	pausedState.append("BackToMenuButtonText", BackToMenuButtonText);


	// Add state to UI states
	state.addUIState(game_states::PAUSED, pausedState);

	/*
		Initialiation of game-over menu
	*/

	UI_State gameOverState("Game-over");

	// Game over text
	std::string gameOverText = "Game over";
	Text GameOverText{ fontLocation, gameOverText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 100 };
	GameOverText.centerOrigin();
	GameOverText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 2.3f))));
	gameOverState.append("GameOverText", GameOverText);

	// Score text
	Text GameOverScoreText{ fontLocation, scoreText, sf::Vector2f(20,20), sf::Vector2f(1,1), [&] {}, 50 };
	GameOverScoreText.jump(sf::Vector2f((screenSize.x / 2) - 100, (screenSize.y / 2 - (screenSize.y / 6.2f))));
	gameOverState.append("GameOverScoreText", GameOverScoreText);

	Text GameOverScoreValue{ fontLocation, tmpScore, sf::Vector2f(85, 20), sf::Vector2f(1,1), [&] {}, 30 };
	GameOverScoreValue.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 - (screenSize.y / 6.2f) + 18)));
	gameOverState.append("GameOverScoreValue", GameOverScoreValue);

	// Retry button
	Button RetryButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Retry clicc" << std::endl; state.setState(game_states::PLAYING); } };
	RetryButton.centerOrigin();
	RetryButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 13))));
	gameOverState.append("RetryButton", RetryButton);

	std::string retryString = "Retry";
	Text RetryText{ fontLocation, retryString, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	RetryText.centerOrigin();
	RetryText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 16.3f))));
	gameOverState.append("RetryText", RetryText);

	// Back to menu button
	Button ReturnToMenuButton{ notClickButton, clickButton, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {std::cout << "Back to menu clicc" << std::endl; state.setState(game_states::MAIN_MENU); } };
	ReturnToMenuButton.centerOrigin();
	ReturnToMenuButton.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 4))));
	gameOverState.append("ReturnToMenuButton", ReturnToMenuButton);

	Text ReturnToMenuText{ fontLocation, backToMenuButtonText, sf::Vector2f(0,0), sf::Vector2f(1,1), [&] {}, 50, sf::Color::Black };
	ReturnToMenuText.centerOrigin();
	ReturnToMenuText.jump(sf::Vector2f((screenSize.x / 2), (screenSize.y / 2 + (screenSize.y / 4.3f))));
	gameOverState.append("ReturnToMenuText", ReturnToMenuText);

	state.addUIState(game_states::GAME_OVER, gameOverState);
}

#endif