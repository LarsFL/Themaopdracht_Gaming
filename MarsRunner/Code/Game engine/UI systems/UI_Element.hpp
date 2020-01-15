#ifndef _UIELEMENTS_HPP
#define _UIELEMENTS_HPP

#include <SFML/Graphics.hpp>
#include <functional>

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

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void onHover() {}
	virtual void onClick() {
		onClickFunc();
	}
	virtual sf::FloatRect getGlobalBounds() = 0;
};



#endif