#ifndef _GAMEOBJECT_HPP
#define _GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <string>

class GameObject {
protected:
	std::string imageLocation;
	sf::Texture image;
	sf::Sprite sprite;
	sf::Vector2f position = { 0,0 };
	sf::Vector2f size = { 0,0 };
	float weight = 0;
	sf::Vector2f velocity = { 0,0 };
	sf::Vector2f acceleration = { 0,0 };
	bool isStatic = true;
	bool isActive = true;
	sf::IntRect rectSourceSprite = { 1, 2, 38, 42 };
public:
	GameObject(std::string imageLocation, sf::Vector2f position, sf::Vector2f size, float weight, bool isStatic = true) :
		imageLocation(imageLocation),
		position(position),
		size(size),
		weight(weight),
		isStatic(isStatic)
	{
		image.loadFromFile(imageLocation);
		sprite.setTexture(image);
		sprite.setPosition(position);
		sprite.setScale(size);
	}

	GameObject(const GameObject& r) :
		imageLocation(r.imageLocation),
		position(r.position),
		size(r.size),
		acceleration(r.acceleration),
		velocity(r.velocity),
		weight(r.weight),
		isStatic(r.isStatic),
		isActive(r.isActive),
		rectSourceSprite(r.rectSourceSprite)
	{
		image.loadFromFile(imageLocation);
		sprite.setTexture(image);
		sprite.setPosition(position);
		sprite.setScale(size);
	}

	void draw(sf::RenderWindow& window) {
		if (isActive) {
			if (!isStatic) {
				sprite.setPosition(position);
			}
			window.draw(sprite);
		}
	}

	void move(sf::Vector2f delta) {
		position += delta;
	}

	void jump(sf::Vector2f target) {
		position = target;
	}

	sf::Vector2f getVelocity() {
		return velocity;
	}

	void setVelocity(sf::Vector2f newVelocity) {
		velocity = newVelocity;
	}

	sf::Vector2f getAcceleration() {
		return acceleration;
	}

	void setAcceleration(sf::Vector2f newAcceleration) {
		acceleration = newAcceleration;
	}

	bool getIsStatic() {
		return isStatic;
	}

	float getWeight() {
		return weight;
	}

	sf::FloatRect getGlobalBounds() {
		return sprite.getGlobalBounds();
	}

	template <class T>
	void callLamba(T a) {
		a();
	}
};

#endif