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
public:
	Button(std::string imageLocation, std::string altImageLocation, sf::Vector2f position, sf::Vector2f scale, std::function< void() > onClickFunc):
		UIElement(position, scale, onClickFunc)
	{
		texture.loadFromFile(imageLocation);
		altTexture.loadFromFile(altImageLocation);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		sprite.setScale(scale);
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
};



#endif
