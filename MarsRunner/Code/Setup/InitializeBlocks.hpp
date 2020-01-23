#ifndef _INITALIZEBLOCKS_HPP
#define _INITALIZEBLOCKS_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Code/Game engine/World generation systems/GenerateBlock.hpp"
#include "Code/Game engine/World generation systems/ObjectBlock.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"

#include "Code/Game engine/Tile systems/Texture.hpp"
#include "Code/Game engine/Tile systems/TextureManager.hpp"
#include "Code/Game engine/Tile systems/Tile.hpp"

void generateBlocks(GenerateBlock& generator, TextureManager& manager) {
	std::string futiristischPlatform = "../Assets/Objects/metalPlatforms.png";
	Texture futiristischPlatformTex{ futiristischPlatform };
	manager.addTexture(1, futiristischPlatformTex);
	sf::IntRect futiristicPlatformRect = { 0, 0, 32, 16 };
	Tile platformTile = { manager, 1, sf::Vector2f{0,0}, sf::Vector2f{1,1}, futiristicPlatformRect };

	std::string boringGroundStr = "../Assets/Objects/groundfixed.png";
	Texture boringGround{ boringGroundStr };
	manager.addTexture(0, boringGround);
	sf::IntRect grounddVar2PlainRect = { 112, 0, 16, 16 };
	sf::IntRect groundVar1PlainRect = { 96, 0, 16, 16 };
	sf::IntRect groundVar0PlainRect = { 80, 0, 16, 16 };

	Tile boring1GroundTile = { manager, 0, sf::Vector2f{0,0}, sf::Vector2f{2,2}, grounddVar2PlainRect };
	Tile boringGroundTile = { manager, 0, sf::Vector2f{0,0}, sf::Vector2f{2,2}, groundVar1PlainRect };
	Tile solidGroundTile = { manager, 0, sf::Vector2f{0,0}, sf::Vector2f{2,2}, groundVar0PlainRect };
	
	ObjectBlock plainGroundBlock = {};

	plainGroundBlock.addObject(sf::Vector2i(0, 20), boringGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(1, 20), boringGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(2, 20), boringGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(3, 20), boringGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(4, 20), boringGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	plainGroundBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(plainGroundBlock);

	ObjectBlock var1GroundBlock = {};
	var1GroundBlock.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	var1GroundBlock.addObject(sf::Vector2i(1, 20), boringGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(2, 20), boringGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	var1GroundBlock.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	var1GroundBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	var1GroundBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(var1GroundBlock);

	ObjectBlock var2GroundBlock = {};
	var2GroundBlock.addObject(sf::Vector2i(0, 20), boringGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	var2GroundBlock.addObject(sf::Vector2i(2, 20), boringGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	var2GroundBlock.addObject(sf::Vector2i(4, 20), boringGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	var2GroundBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(var2GroundBlock);

	ObjectBlock var2PlatformBlock = {};
	var2PlatformBlock.addObject(sf::Vector2i(1, 15), platformTile);
	var2PlatformBlock.addObject(sf::Vector2i(2, 15), platformTile);
	var2PlatformBlock.addObject(sf::Vector2i(3, 15), platformTile);
	var2PlatformBlock.addObject(sf::Vector2i(0, 20), boringGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(2, 20), boringGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(4, 20), boringGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	var2PlatformBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(var2PlatformBlock);

	ObjectBlock var3PlatformBlock = {};
	var3PlatformBlock.addObject(sf::Vector2i(2, 17), platformTile);
	var3PlatformBlock.addObject(sf::Vector2i(3, 17), platformTile);
	var3PlatformBlock.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(1, 20), boringGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(2, 20), boringGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(3, 20), boringGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	var3PlatformBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(var3PlatformBlock);

	ObjectBlock var4PlatformBlock = {};
	var4PlatformBlock.addObject(sf::Vector2i(1, 18), platformTile);
	var4PlatformBlock.addObject(sf::Vector2i(2, 18), platformTile);
	var4PlatformBlock.addObject(sf::Vector2i(4, 14), platformTile);
	var4PlatformBlock.addObject(sf::Vector2i(5, 14), platformTile);
	var4PlatformBlock.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(1, 20), boringGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(2, 20), boringGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(3, 20), boringGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	var4PlatformBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(var4PlatformBlock);
}

#endif