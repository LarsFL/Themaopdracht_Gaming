#ifndef _UI_STATE_HPP
#define _UI_STATE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "UI_Element.hpp"

class UI_State {
private:
	std::vector<UIElement*> elements = {};
	std::string name;
public:
	UI_State(std::string name = "") : name(name) {}

	void append(UIElement* newElement) {
		elements.push_back(newElement);
	}

	void draw(sf::RenderWindow & window) {
		for (auto element : elements) {
			element->draw(window);
		}
	}

	std::string getName() {
		return name;
	}
};

#endif