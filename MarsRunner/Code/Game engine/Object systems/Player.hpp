#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"
#include <vector>
#include <iostream>

#include "GameObject.hpp"

class Player : public GameObject {
protected:
	bool isGround = false;
	sf::RenderWindow& window;
	std::vector<GameObject>& groundObjects;
	//std::vector<action>& actions;

	std::vector<action> actions = {
		action(sf::Keyboard::Up,
		[&]() {
		if (this->isOnGround()) {
			this->isOnGround(false);
			this->setAcceleration(sf::Vector2f{ 0.0, 0.3 });
			this->setVelocity(sf::Vector2f{ 0.0, -10.0 });
		}
		}),


		action(sf::Keyboard::Left,  [&]() { if (!isLeftIntersecting(*this, groundObjects[0])) { this->move(sf::Vector2f(-1, 0)); } }),

		action(sf::Keyboard::Down,
		[&]() {
		for (auto& groundObject : groundObjects)
		{
			if (isObjOnGround(*this, groundObject)) { return; }
		}

		this->move(sf::Vector2f(0, 1));
		}),

		action(sf::Keyboard::Right, [&]() { if (!isRightIntersecting(*this, groundObjects[0])) { this->move(sf::Vector2f(1, 0)); } }),

	};

public:
	Player(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, float weight,
		bool isStatic, sf::RenderWindow& window, std::vector<GameObject>& groundObjects) :

		GameObject(imageLocation, position, size, weight, isStatic),
		window(window),
		groundObjects(groundObjects)
	{
		image.loadFromFile(imageLocation);
		sprite.setTexture(image);
		sprite.setPosition(position);
		sprite.setScale(size);
	}

	bool isOnGround() {
		return isGround;
	}

	void isOnGround(bool setTo) {
		isGround = setTo;
	}

	void update() {
		this->isOnGround(false);

		for (auto& groundObject : groundObjects) {
			//groundObject.draw(window);

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
			this->setVelocity(sf::Vector2f{ 0.0, 0.0 });
		}
		this->draw(window);
	}

};



#endif //PLAYER_HPP