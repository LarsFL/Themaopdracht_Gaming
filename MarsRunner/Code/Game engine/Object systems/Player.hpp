#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Code/Game engine/Input systems/input.hpp"
#include "Code/Game engine/Physics systems/physics.hpp"
#include "Code/Game engine/Object systems/Projectile.hpp"
#include <vector>
#include <iostream>

#include "GameObject.hpp"

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
		action(sf::Keyboard::Space, [&]() { if (!spacePressed) { projectiles.push_back(Projectile("../Assets/Objects/bullet.png", position, sf::Vector2f(1,1), sf::Vector2f(10,0))); spacePressed = true; } }),
		action([&]() { return !sf::Keyboard::isKeyPressed(sf::Keyboard::Space); }, [&]() { spacePressed = false; })
	};

public:
	Player(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, float weight,
		bool isStatic, sf::RenderWindow& window, std::vector<GameObject>& groundObjects) :

		GameObject(imageLocation, position, size, weight, isStatic),
		window(window),
		groundObjects(groundObjects) {}

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

	void update() {
		this->isOnGround(false);

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
			this->setVelocity(sf::Vector2f{ 0.0, 0.0 });
		}

		unsigned int count = 0;
		for (auto& projectile : projectiles) {
			if (projectile.update(groundObjects)) {
				projectiles.erase(projectiles.begin() + count);
			}
			count++;
		}

		this->draw(window);
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

};



#endif //PLAYER_HPP