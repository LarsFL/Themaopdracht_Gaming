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

	UI_State(const UI_State& a) : name(a.name) {
		for (auto element : a.elements) {
			elements.push_back(element->clone());
		}
	}

	void append(UIElement &newElement) {
		elements.push_back(newElement.clone());
	}

	void draw(sf::RenderWindow & window) {
		for (auto element : elements) {
			element->draw(window);
		}
	}

	std::string getName() {
		return name;
	}

	void update(sf::Vector2f& mouse_pos) {
		for (auto element : elements) {
			if (element->getGlobalBounds().contains(mouse_pos)) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					element->onClick();
				}
				else {
					element->onHover();
				}
			}
		}
	}
};

#endif