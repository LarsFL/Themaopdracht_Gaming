#ifndef _TEXTUREMANAGER_HPP
#define _TEXTUREMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

#include "Texture.hpp"

class TextureManager {
private:
	std::map<int, std::shared_ptr<Texture>> textures;
public:
	TextureManager() {};

	void addTexture(int id, Texture& texture) {
		textures[id] = std::make_shared<Texture>(texture);
	}

	std::shared_ptr<Texture> getTexture(int id) {
		return textures[id];
	}
};

#endif