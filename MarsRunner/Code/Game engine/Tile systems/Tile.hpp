#ifndef _TILE_HPP
#define _TILE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "TextureManager.hpp"
#include "Texture.hpp"

class Tile {
private:
	std::shared_ptr<Texture> texture;
	int textureId;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f size;
	TextureManager& manager;
public:
	Tile(TextureManager& manager, int textureId, sf::Vector2f position, sf::Vector2f size, sf::IntRect textureRect) :
		textureId(textureId),
		position(position),
		size(size),
		manager(manager)
	{
		texture = manager.getTexture(textureId);
		sprite.setTexture(texture->texture);
		sprite.setPosition(position);
		sprite.setTextureRect(textureRect);
		sprite.setScale(size);
	};

	Tile(const Tile& r) :
		texture(r.texture),
		textureId(r.textureId),
		sprite(r.sprite),
		position(r.position),
		size(r.size),
		manager(r.manager)
	{
		sprite.setTexture(texture->texture);
		sprite.setPosition(position);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	void setPosition(sf::Vector2f newPos) {
		position = newPos;
		sprite.setPosition(newPos);
	}

	sf::FloatRect getGlobalBounds() {
		return sprite.getGlobalBounds();
	}
};

#endif