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
	var4PlatformBlock.addObject(sf::Vector2i(3, 14), platformTile);
	var4PlatformBlock.addObject(sf::Vector2i(4, 14), platformTile);
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

	ObjectBlock smallHillBlock = {};
	smallHillBlock.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	smallHillBlock.addObject(sf::Vector2i(1, 18), boringGroundTile);
	smallHillBlock.addObject(sf::Vector2i(2, 18), boringGroundTile);
	smallHillBlock.addObject(sf::Vector2i(3, 18), boringGroundTile);
	smallHillBlock.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	smallHillBlock.addObject(sf::Vector2i(1, 20), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(2, 20), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(3, 20), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(1, 19), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(2, 19), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(3, 19), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	smallHillBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(smallHillBlock);


	ObjectBlock caveBlock = {};
	caveBlock.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	caveBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	caveBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	caveBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	caveBlock.addObject(sf::Vector2i(1, 21), boringGroundTile);
	caveBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	caveBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);
	caveBlock.addObject(sf::Vector2i(2, 22), boringGroundTile);
	caveBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);
	caveBlock.addObject(sf::Vector2i(3, 22), boringGroundTile);
	caveBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);
	caveBlock.addObject(sf::Vector2i(4, 22), boring1GroundTile);
	caveBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(caveBlock);

	ObjectBlock bridgeBlock = {};
	bridgeBlock.addObject(sf::Vector2i(0, 20), platformTile);
	bridgeBlock.addObject(sf::Vector2i(1, 20), platformTile);
	bridgeBlock.addObject(sf::Vector2i(2, 20), platformTile);
	bridgeBlock.addObject(sf::Vector2i(3, 20), platformTile);
	bridgeBlock.addObject(sf::Vector2i(4, 20), platformTile);
	generator.addBlock(bridgeBlock);

	ObjectBlock biggHillBlock = {};
	biggHillBlock.addObject(sf::Vector2i(0, 16), boringGroundTile);
	biggHillBlock.addObject(sf::Vector2i(0, 17), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(0, 18), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(0, 19), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(0, 20), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(0, 21), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);

	biggHillBlock.addObject(sf::Vector2i(1, 12), boringGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 13), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 14), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 15), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 16), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 17), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 18), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 19), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 20), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 21), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);

	biggHillBlock.addObject(sf::Vector2i(2, 12), boringGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 13), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 14), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 15), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 16), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 17), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 18), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 19), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 20), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 21), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 22), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(2, 23), solidGroundTile);

	biggHillBlock.addObject(sf::Vector2i(3, 12), boringGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 13), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 14), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 15), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 16), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 17), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 18), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 19), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 20), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 21), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 22), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(3, 23), solidGroundTile);

	biggHillBlock.addObject(sf::Vector2i(4, 12), boringGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 13), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 14), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 15), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 16), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 17), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 18), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 19), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 20), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 21), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 22), solidGroundTile);
	biggHillBlock.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(biggHillBlock);

	ObjectBlock highPlatform = {};
	highPlatform.addObject(sf::Vector2i(1, 15), platformTile);
	highPlatform.addObject(sf::Vector2i(2, 15), platformTile);

	highPlatform.addObject(sf::Vector2i(3, 15), platformTile);

	highPlatform.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	highPlatform.addObject(sf::Vector2i(1, 20), boringGroundTile);
	highPlatform.addObject(sf::Vector2i(2, 20), boringGroundTile);
	highPlatform.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	highPlatform.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	highPlatform.addObject(sf::Vector2i(0, 21), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(1, 21), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(2, 21), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(3, 21), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(4, 21), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(0, 22), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(1, 22), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(2, 22), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(3, 22), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(4, 22), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(0, 23), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(1, 23), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(2, 23), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(3, 23), solidGroundTile);
	highPlatform.addObject(sf::Vector2i(4, 23), solidGroundTile);
	generator.addBlock(highPlatform);

	generator.addStartBlock(plainGroundBlock);
	generator.addStartBlock(var1GroundBlock);
	generator.addStartBlock(var2GroundBlock);
}

#endif