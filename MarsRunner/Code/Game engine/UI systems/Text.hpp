#ifndef _TEXT_HPP
#define _TEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

#include "UI_Element.hpp"

class Text : public UIElement {
private:
	sf::Font font;
	sf::Text text;
public:
	Text(std::string fontLocation, std::string stringText, sf::Vector2f position, sf::Vector2f scale, std::function< void() > onClickFunc) :
		UIElement(position, scale, onClickFunc)
	{
		if (!font.loadFromFile(fontLocation)) {
			std::cout << "ERROR LOADING FONT";
		}
		text.setFont(font);
		text.setPosition(position);
		text.setString(stringText);
		text.setCharacterSize(25);
		text.setFillColor(sf::Color::White);
	}

	void draw(sf::RenderWindow& window) override {
		window.draw(text);
	}

	void setText(std::string newText) {
		text.setString(newText);
	}

	sf::FloatRect getGlobalBounds() override {
		return text.getGlobalBounds();
	}
};

#endif