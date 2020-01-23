#ifndef _UIELEMENTS_HPP
#define _UIELEMENTS_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

class UIElement {
protected:
	sf::Vector2f position;
	sf::Vector2f size;
	std::function< void() > onClickFunc;
public:
	UIElement(sf::Vector2f position, sf::Vector2f size, std::function< void() > onClickFunc) :
		position(position),
		size(size),
		onClickFunc(onClickFunc)
	{}

	UIElement(const UIElement& a) :
		position(a.position),
		size(a.size),
		onClickFunc(a.onClickFunc) {}

	virtual void draw(sf::RenderWindow& window) { std::cout << "Wrong draw called" << std::endl; };
	virtual void onHover() {}
	virtual void onClick() {
		onClickFunc();
	}
	virtual sf::FloatRect getGlobalBounds() {
		return sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
	};
	virtual void setOrigin(sf::Vector2f origin) {};
	virtual void centerOrigin() {};
	virtual void jump(sf::Vector2f newPos) {};
	virtual void setText(std::string text) {};

	virtual UIElement* clone() const = 0;
};



#endif