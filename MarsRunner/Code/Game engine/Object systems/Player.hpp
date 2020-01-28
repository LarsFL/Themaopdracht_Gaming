#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"
#include "Code/Game engine/Object systems/Projectile.hpp"
#include "../World generation systems/ObjectBlock.hpp"
#include "../World Speed Systems/view.hpp"
#include "Code/Game engine/Tile systems/Tile.hpp"
#include "../../Setup/GameState.hpp"

#include <vector>
#include <deque>
#include <iostream>

#include "GameObject.hpp"
#include "Code/Game engine/Audio systems/AudioManager.hpp"

enum class playerStates {
	IDLE,
	WALK,
	WALK_LEFT,
	WALK_RIGHT,
	JUMP,
	DOWN,
	SHOOT,
	DAMAGE,
	DEATH
};

class Player : public GameObject {
protected:
	bool isGround = false;
	sf::RenderWindow& window;
	std::deque<ObjectBlock>& groundObjects;
	sf::View& currentView;
	GameState& gameState;
	std::vector<Projectile> projectiles;
	bool spacePressed = false;
	float viewMoveSpeed = 0.f;
	bool isJumping = false;

	float maxX_points = 0.f;
	AudioManager& audio;


	std::vector<action> actions = {

		action(sf::Keyboard::Left,  [&]() {

		for (auto& groundObject : groundObjects) {
			if (isLeftIntersecting(*this, groundObject)) {
				return;
			}
		}

		lastState = state;
		state = playerStates::WALK_LEFT;
		}),


		action(sf::Keyboard::Right, [&]() { 
			
		for (auto& groundObject : groundObjects) {
			if (isRightIntersecting(*this, groundObject)) {
				return;
			}
		}

		if (isRightIntersecting(*this, getViewBounds(currentView)))
		{
			return;
		}

		lastState = state;
		state = playerStates::WALK_RIGHT;
		}),


		action(sf::Keyboard::Down,
		[&]() {
			lastState = state;
			state = playerStates::DOWN;
		}),

		action(sf::Keyboard::Up,
		[&]() {
			if (this->isOnGround() && !isJumping) {
				isJumping = true;
				lastState = state;
				state = playerStates::JUMP;
			}
		}),

		action([&]() { return !sf::Keyboard::isKeyPressed(sf::Keyboard::Space); },
		[&]() {
			spacePressed = false;
		}),

		action(sf::Keyboard::Space,
		[&]() {
			lastState = state;
			state = playerStates::SHOOT;
		}),

		action([&]() {return !sf::Keyboard::isKeyPressed(sf::Keyboard::Up); }, [&]() { isJumping = false; })
	};
	playerStates state = playerStates::IDLE;
	playerStates lastState = state;

public:
	Player(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, float weight,
		bool isStatic, bool animated, sf::RenderWindow& window, std::deque<ObjectBlock>& groundObjects, sf::View& currentView, GameState& gameState, AudioManager& audio) :

		GameObject(imageLocation, position, size, weight, isStatic, animated),
		window(window),
		groundObjects(groundObjects),
		currentView(currentView),
		gameState(gameState),
		audio(audio)
		{
			image.loadFromFile(imageLocation);
			sprite.setTexture(image);
			sprite.setPosition(position);
			sprite.setScale(size);
		}

	Player(const Player& a) :
		GameObject(a.imageLocation, a.position, a.size, a.weight, a.isStatic, a.animated),
		window(a.window),
		groundObjects(a.groundObjects),
		currentView(a.currentView),
		gameState(a.gameState),
		audio(a.audio)
	{}

	bool isOnGround() {
		return isGround;
	}

	void isOnGround(bool setTo) {
		isGround = setTo;
	}

	void update(float & minSpeed) {

		maxX_points = getViewBounds(currentView).left + getViewBounds(currentView).width;

		gameState.setScore(maxX_points / 3);

		if (isLeftIntersecting(*this, getViewBounds(currentView))) {
			state = playerStates::DEATH;
			gameState.setState(game_states::GAME_OVER);
			std::cout << "DEAD" << std::endl;
			return;
		}

		state = playerStates::WALK;

		this->isOnGround(false);

		viewMoveSpeed = getViewMoveSpeed();

		bool rightIntersected = false;

		for (auto& groundObject : groundObjects) {
			if (isRightIntersecting(*this, groundObject)) {
				rightIntersected = true;
			}
		}

		if (!rightIntersected)
		{
			if (viewMoveSpeed < minSpeed) {
				this->move(sf::Vector2f{ 0.5, 0 });
			}
			else {
				this->move(sf::Vector2f{ viewMoveSpeed, 0 });
			}
		}
		else
		{
			state = playerStates::IDLE;
		}
		

		for (auto& groundObject : groundObjects) {
			if (isObjOnGround(*this, groundObject)) {
				this->isOnGround(true);
			}
		}

		for (auto& action : actions) {
			action();
		}

		if (!this->isOnGround()) {
			sf::Vector2f velocity = this->getVelocity();
			velocity += this->getAcceleration();
			this->setVelocity(velocity);
			this->move(this->getVelocity());
		}
		else
		{
			if (this->getVelocity().y < 0.0) {
				sf::Vector2f velocity = this->getVelocity();
				velocity += this->getAcceleration();
				this->setVelocity(velocity);
				this->move(this->getVelocity());
			}
			
			else {
				this->setVelocity(sf::Vector2f{ 0.0, 0.0 });
			}
		}
		unsigned int count = 0;
		for (auto& projectile : projectiles) {
			if (projectile.update(groundObjects)) {
				projectiles.erase(projectiles.begin() + count);
			}
			count++;
		}
	}

	void drawProjectiles(sf::FloatRect& view) {
		unsigned int i = 0;
		for (auto& projectile : projectiles) {
			if (!projectile.getGlobalBounds().intersects(view)) {
				projectiles.erase(projectiles.begin() + i);
			}
			i++;
		}
		for (auto& projectile : projectiles) {
			projectile.draw(window);
		}

	}

	void setPlayerAnimationState(std::map<std::string, AnimationStates>& animationsMap){
		switch (state) {
			case(playerStates::IDLE): {
				animationsMap["player"].setState(PossibleStates::IDLE);
				animationsMap["player"].setGameSpeed(viewMoveSpeed);
				break;
			}

			case(playerStates::WALK): {
				animationsMap["player"].setState(PossibleStates::WALK);
				animationsMap["player"].setGameSpeed(viewMoveSpeed);
				break;
			}

			case(playerStates::WALK_LEFT): {
				this->move(sf::Vector2f((viewMoveSpeed + 6) * -1, 0));

				animationsMap["player"].setState(PossibleStates::WALK_LEFT);
				animationsMap["player"].setGameSpeed(viewMoveSpeed);
				break;
			}

			case(playerStates::WALK_RIGHT): {
				this->move(sf::Vector2f(viewMoveSpeed + 6, 0));

				animationsMap["player"].setGameSpeed(viewMoveSpeed);
				animationsMap["player"].setState(PossibleStates::WALK_RIGHT);
				break;
			}

			case(playerStates::JUMP): {
				if (this->isOnGround()) {
					this->isOnGround(false);
					this->setAcceleration(sf::Vector2f{ 0.0, 0.35 });
					this->setVelocity(sf::Vector2f{ 0.0, -12.0 });
				}
				//state = playerStates::IDLE;

				//niet zeker of dit de goede animatie is
				animationsMap["player"].setState(PossibleStates::JUMP_START_IMPACT);
				animationsMap["player"].setGameSpeed(viewMoveSpeed);
				break;
			}

			case(playerStates::DOWN): {
				for (auto& groundObject : groundObjects)
				{
					if (isObjOnGround(*this, groundObject)) { return; }
				}

				this->move(sf::Vector2f(0, 10));//was 0,2
				break;
			}

			case(playerStates::SHOOT): {
				sf::Vector2f ProjectilePosition(position.x, position.y + 25);
				if (lastState == playerStates::WALK_LEFT) {
					//make projectile
					if (!spacePressed) {
						projectiles.push_back(Projectile("../assets/objects/bullet.png", ProjectilePosition, sf::Vector2f(1, 1), sf::Vector2f( (viewMoveSpeed*-1)-10, 0)));
						audio.playSound("pew");
						spacePressed = true;
					}
				}
				else {
					//make projectile
					if (!spacePressed) {
						projectiles.push_back(Projectile("../assets/objects/bullet.png", ProjectilePosition, sf::Vector2f(1, 1), sf::Vector2f(viewMoveSpeed + 10, 0)));
						audio.playSound("pew");
						spacePressed = true;
					}
				}


				animationsMap["player"].setState(PossibleStates::SHOOT);
				animationsMap["player"].setGameSpeed(0.f);
				break;
			}

			case(playerStates::DAMAGE): {
				animationsMap["player"].setState(PossibleStates::DAMAGED);
				animationsMap["player"].setGameSpeed(0.f);
				break;
			}

			case(playerStates::DEATH): {
				animationsMap["player"].setState(PossibleStates::DEATH);
				animationsMap["player"].setGameSpeed(0.f);
				break;
			}
		}
	}

	void setPlayerState(playerStates newState) {
		state = newState;
	}


};


#endif //PLAYER_HPP