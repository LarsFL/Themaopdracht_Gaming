#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"
#include "Code/Game engine/Object systems/Projectile.hpp"
#include "../World Speed Systems/view.hpp"
#include <vector>
#include <iostream>

#include "GameObject.hpp"

enum class playerStates {
	IDLE,
	WALK,
	WALK_LEFT,
	WALK_RIGHT,
	JUMP,
	SHOOT,
	DAMAGE,
	DEATH
};

class Player : public GameObject {
protected:
	bool isGround = false;
	sf::RenderWindow& window;
	std::vector<GameObject>& groundObjects;
	std::vector<Projectile> projectiles;
	bool spacePressed = false;

	std::vector<action> actions = {
		action(sf::Keyboard::Up,
		[&]() {
		if (this->isOnGround()) {
			this->isOnGround(false);
			this->setAcceleration(sf::Vector2f{ 0.0, 0.35 });
			this->setVelocity(sf::Vector2f{ 0.0, -12.0 });
			state = playerStates::JUMP;
		}
		}),


		action(sf::Keyboard::Left,  [&]() { if (!isLeftIntersecting(*this, groundObjects[0])) { 
			this->move(sf::Vector2f(-5, 0));
			state = playerStates::WALK_LEFT;
		} }),

		action(sf::Keyboard::Down,
		[&]() {
		for (auto& groundObject : groundObjects)
		{
			if (isObjOnGround(*this, groundObject)) { return; }
		}

		this->move(sf::Vector2f(0, 2));
		}),

		action(sf::Keyboard::Right, [&]() { if (!isRightIntersecting(*this, groundObjects[0])) { 
			this->move(sf::Vector2f(5, 0));
			state = playerStates::WALK_RIGHT;
		} }),
		action(sf::Keyboard::Space, [&]() { if (!spacePressed) { 
			projectiles.push_back(Projectile("../Assets/Objects/bullet.png", position, sf::Vector2f(1,1), sf::Vector2f(10,0)));
			spacePressed = true;
			playerStates state = playerStates::SHOOT;
		} }),
		action([&]() { return !sf::Keyboard::isKeyPressed(sf::Keyboard::Space); }, [&]() { spacePressed = false; })
	};
	playerStates state = playerStates::IDLE;

public:
	Player(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, float weight,
		bool isStatic, bool animated, sf::RenderWindow& window, std::vector<GameObject>& groundObjects) :

		GameObject(imageLocation, position, size, weight, isStatic, animated),
		window(window),
		groundObjects(groundObjects) {
		image.loadFromFile(imageLocation);
		sprite.setTexture(image);
		sprite.setPosition(position);
		sprite.setScale(size);
	}

	Player(const Player& a) :
		GameObject(a.imageLocation, a.position, a.size, a.weight, a.isStatic),
		window(a.window),
		groundObjects(a.groundObjects)
	{}

	bool isOnGround() {
		return isGround;
	}

	void isOnGround(bool setTo) {
		isGround = setTo;
	}

	void update(float & minSpeed) {
		//state = playerStates::WALK;
		this->isOnGround(false);

		float viewMoveSpeed = getViewMoveSpeed();

		if (viewMoveSpeed < minSpeed) {
			this->move(sf::Vector2f{ 0.5, 0 });
		}
		else {
			this->move(sf::Vector2f{ viewMoveSpeed, 0 });
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
			else {
				i++;
			}
		}
		for (auto& projectile : projectiles) {
			projectile.draw(window);
		}

	}

	void setPlayerAnimationState(std::map<std::string, AnimationStates>& animationsMap){
		switch (state) {
			case(playerStates::IDLE): {
				animationsMap["player"].setState(PossibleStates::IDLE);
				break;
			}
			case(playerStates::WALK): {
				animationsMap["player"].setState(PossibleStates::WALK);
				break;
			}
			case(playerStates::WALK_LEFT): {
				animationsMap["player"].setState(PossibleStates::WALK_LEFT);
				break;
			}
			case(playerStates::WALK_RIGHT): {
				animationsMap["player"].setState(PossibleStates::WALK_RIGHT);
				break;
			}
			case(playerStates::JUMP): {
				//niet zeker
				animationsMap["player"].setState(PossibleStates::JUMP_START_IMPACT);
				
				break;
			}
			case(playerStates::SHOOT): {
				animationsMap["player"].setState(PossibleStates::SHOOT);
				break;
			}
			case(playerStates::DAMAGE): {
				animationsMap["player"].setState(PossibleStates::DAMAGED);
				break;
			}
			case(playerStates::DEATH): {
				animationsMap["player"].setState(PossibleStates::DEATH);
				break;
			}
		}
	}


};


#endif //PLAYER_HPP