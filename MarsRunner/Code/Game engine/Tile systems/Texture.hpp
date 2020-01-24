#ifndef _TEXTURE_HPP
#define _TEXTURE_HPP

#include <SFML/Graphics.hpp>
#include <string>


class Texture {
public:
	sf::Texture texture;
	Texture(std::string imageLocation) {
		texture.loadFromFile(imageLocation);
	}
};


#endif