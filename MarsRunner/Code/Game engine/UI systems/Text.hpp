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
	std::string stringText;
	sf::Vector2f position;
	int textSize;
	sf::Color color;
public:
	Text(std::string fontLocation, 
		std::string stringText, 
		sf::Vector2f position, 
		sf::Vector2f scale, 
		std::function< void() > onClickFunc, 
		int textSize = 25,
		sf::Color color = sf::Color::White
		) :
		UIElement(position, scale, onClickFunc),
		stringText(stringText),
		position(position),
		textSize(textSize),
		color(color)
	{
		if (!font.loadFromFile(fontLocation)) {
			std::cout << "ERROR LOADING FONT";
		}
		text.setFont(font);
		text.setPosition(position);
		text.setString(stringText);
		text.setCharacterSize(textSize);
		text.setFillColor(color);
	}

	Text(const Text& a) :
		UIElement(a),
		font(a.font),
		text(a.text),
		stringText(a.stringText),
		position(a.position),
		textSize(a.textSize),
		color(a.color)
	{
		text.setFont(font);
		text.setPosition(position);
		text.setString(stringText);
		text.setCharacterSize(textSize);
		text.setFillColor(color);
	}

	virtual Text* clone() const {
		return new Text(*this);
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

	void setOrigin(sf::Vector2f origin) override {
		text.setOrigin(origin);
	}

	void centerOrigin() override {
		setOrigin(sf::Vector2f(getGlobalBounds().width / 2, getGlobalBounds().height / 2));
	}

	void jump(sf::Vector2f newPos) override {
		text.setPosition(newPos);
		position = newPos;
	}
};

#endif