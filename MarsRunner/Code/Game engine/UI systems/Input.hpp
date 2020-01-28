#ifndef _INPUT_HPP
#define _INPUT_HPP

#include "Code/Game engine/UI systems/Text.hpp"

class Input : public UIElement {
protected:
	sf::Font font;
	sf::Text text;
	std::string stringText;
	sf::Vector2f position;
	int textSize;
	sf::Color color;
	bool enterText = false;
public:
	Input(std::string fontLocation,
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

	Input(const Input& a) :
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

	virtual Input* clone() const {
		return new Input(*this);
	}

	void draw(sf::RenderWindow& window) override {
		window.draw(text);
	}

	void setText(std::string newText) override {
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