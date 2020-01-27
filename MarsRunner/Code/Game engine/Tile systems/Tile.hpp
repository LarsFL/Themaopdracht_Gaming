#ifndef _TILE_HPP
#define _TILE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "TextureManager.hpp"
#include "Texture.hpp"
#include "../Object systems/WorldObject.hpp"
#include "../Object systems/PickUp.hpp"

class Tile : public WorldObject {
private:
	std::shared_ptr<Texture> texture;
	int textureId;
	sf::Sprite sprite;
	TextureManager& manager;

public:
	Tile(TextureManager& manager, int textureId, sf::Vector2f position, sf::Vector2f size, sf::IntRect textureRect) :
		WorldObject(position, size), 
		textureId(textureId),
		manager(manager)
	{
		texture = manager.getTexture(textureId);
		sprite.setTexture(texture->texture);
		sprite.setPosition(position);
		sprite.setTextureRect(textureRect);
		sprite.setScale(size);
	};

	Tile(const Tile& r) :
		WorldObject(r.position, r.size),
		texture(r.texture),
		textureId(r.textureId),
		sprite(r.sprite),
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