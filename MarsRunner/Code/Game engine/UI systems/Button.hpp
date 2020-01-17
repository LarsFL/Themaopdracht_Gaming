#ifndef _BUTTON_HPP
#define _BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <functional>

#include "UI_Element.hpp"

class Button : public UIElement {
private:
	sf::Texture texture;
	sf::Texture altTexture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f scale;
public:
	Button(std::string imageLocation, std::string altImageLocation, sf::Vector2f position, sf::Vector2f scale, std::function< void() > onClickFunc):
		UIElement(position, scale, onClickFunc),
		position(position),
		scale(scale)
	{
		texture.loadFromFile(imageLocation);
		altTexture.loadFromFile(altImageLocation);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		sprite.setScale(scale);
	}

	Button(const Button& a) :
		UIElement(a),
		texture(a.texture),
		altTexture(a.altTexture),
		sprite(a.sprite),
		position(a.position),
		scale(a.scale)
	{
		sprite.setPosition(position);
		sprite.setScale(scale);
	}

	virtual Button* clone() const {
		return new Button(*this);
	}

	void draw(sf::RenderWindow& window) override {
		window.draw(sprite);
		sprite.setTexture(texture);
	}

	void onHover() override {
		sprite.setTexture(altTexture);
	}

	sf::FloatRect getGlobalBounds() override {
		return sprite.getGlobalBounds();
	}

	void setOrigin(sf::Vector2f origin) override {
		sprite.setOrigin(origin);
	}

	void centerOrigin() override {
		setOrigin(sf::Vector2f(getGlobalBounds().width / 2, getGlobalBounds().height / 2));
	}

	void jump(sf::Vector2f newPos) override {
		sprite.setPosition(newPos);
		position = newPos;
	}
};



#endif
