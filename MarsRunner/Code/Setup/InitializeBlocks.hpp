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

	std::string coinPath = "../Assets/Objects/coin.png";
	Texture coinTex{ coinPath };
	manager.addTexture(2, coinTex);

	std::string enemy1Path = "../Assets/Objects/smallAlien.png";
	Texture enemy1Tex{ enemy1Path };
	manager.addTexture(3, enemy1Tex);

	std::string enemy2Path = "../Assets/Objects/smallGreenAlien.png";
	Texture enemy2Tex{ enemy2Path };
	manager.addTexture(4, enemy2Tex);

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

	ObjectBlock lisaBlock1 = {};
	lisaBlock1.addObject(sf::Vector2i(1, 11), platformTile);
	lisaBlock1.addObject(sf::Vector2i(2, 11), platformTile);
	lisaBlock1.addObject(sf::Vector2i(3, 11), platformTile);
	lisaBlock1.addObject(sf::Vector2i(4, 11), platformTile);
	lisaBlock1.addObject(sf::Vector2i(5, 11), platformTile);

	lisaBlock1.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock1.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(0, 23), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock1.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock1.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock1.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(5, 23), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock1.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock1.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock1);

	ObjectBlock lisaBlock2 = {};
	lisaBlock2.addObject(sf::Vector2i(1, 2), platformTile);
	lisaBlock2.addObject(sf::Vector2i(2, 2), platformTile);
	lisaBlock2.addObject(sf::Vector2i(3, 2), platformTile);
	lisaBlock2.addObject(sf::Vector2i(4, 2), platformTile);
	lisaBlock2.addObject(sf::Vector2i(5, 2), platformTile);

	lisaBlock2.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock2.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(0, 23), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock2.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock2.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock2.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock2.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock2.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock2.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock2.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock2.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock2.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(5, 23), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock2.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock2.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock2);

	ObjectBlock lisaBlock3 = {};
	lisaBlock3.addObject(sf::Vector2i(1, 8), platformTile);
	lisaBlock3.addObject(sf::Vector2i(2, 8), platformTile);
	lisaBlock3.addObject(sf::Vector2i(3, 8), platformTile);
	lisaBlock3.addObject(sf::Vector2i(4, 8), platformTile);
	lisaBlock3.addObject(sf::Vector2i(5, 8), platformTile);

	lisaBlock3.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock3.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(0, 23), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock3.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock3.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock3.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock3.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock3.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock3.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock3.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock3.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock3.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(5, 23), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock3.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock3.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock3);

	ObjectBlock lisaBlock4 = {};
	lisaBlock4.addObject(sf::Vector2i(1, 14), platformTile);
	lisaBlock4.addObject(sf::Vector2i(2, 14), platformTile);
	lisaBlock4.addObject(sf::Vector2i(3, 14), platformTile);
	lisaBlock4.addObject(sf::Vector2i(4, 14), platformTile);
	lisaBlock4.addObject(sf::Vector2i(5, 14), platformTile);

	lisaBlock4.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock4.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(0, 23), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock4.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock4.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock4.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock4.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock4.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock4.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock4.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock4.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock4.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(5, 23), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock4.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock4.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock4);

	ObjectBlock lisaBlock5 = {};
	lisaBlock5.addObject(sf::Vector2i(2, 4), platformTile);
	lisaBlock5.addObject(sf::Vector2i(3, 4), platformTile);
	lisaBlock5.addObject(sf::Vector2i(4, 4), platformTile);
	lisaBlock5.addObject(sf::Vector2i(5, 4), platformTile);

	lisaBlock5.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock5.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(0, 23), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock5.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock5.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock5.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock5.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock5.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock5.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock5.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock5.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock5.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(5, 23), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock5.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock5.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock5);

	ObjectBlock lisaBlock6 = {};
	lisaBlock6.addObject(sf::Vector2i(4, 10), platformTile);
	lisaBlock6.addObject(sf::Vector2i(5, 10), platformTile);
	lisaBlock6.addObject(sf::Vector2i(6, 10), platformTile);

	lisaBlock6.addObject(sf::Vector2i(0, 16), boring1GroundTile);
	lisaBlock6.addObject(sf::Vector2i(0, 17), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(0, 18), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(0, 19), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(0, 20), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(0, 23), solidGroundTile);

	lisaBlock6.addObject(sf::Vector2i(1, 16), boring1GroundTile);
	lisaBlock6.addObject(sf::Vector2i(1, 17), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(1, 18), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(1, 19), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(1, 20), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock6.addObject(sf::Vector2i(2, 18), boring1GroundTile);
	lisaBlock6.addObject(sf::Vector2i(2, 19), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(2, 20), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock6.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock6.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock6.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock6.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock6.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock6.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(5, 23), solidGroundTile);

	lisaBlock6.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock6.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock6.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock6);

	ObjectBlock lisaBlock7 = {};
	lisaBlock7.addObject(sf::Vector2i(4, 14), platformTile);
	lisaBlock7.addObject(sf::Vector2i(5, 14), platformTile);
	lisaBlock7.addObject(sf::Vector2i(6, 14), platformTile);

	lisaBlock7.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock7.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(0, 23), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock7.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock7.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock7.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock7.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock7.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock7.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock7.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock7.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock7.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(5, 23), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock7.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock7.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock7);

	ObjectBlock lisaBlock8 = {};
	lisaBlock8.addObject(sf::Vector2i(4, 12), platformTile);
	lisaBlock8.addObject(sf::Vector2i(5, 12), platformTile);
	lisaBlock8.addObject(sf::Vector2i(6, 12), platformTile);

	lisaBlock8.addObject(sf::Vector2i(1, 7), platformTile);
	lisaBlock8.addObject(sf::Vector2i(2, 7), platformTile);
	lisaBlock8.addObject(sf::Vector2i(3, 7), platformTile);

	lisaBlock8.addObject(sf::Vector2i(0, 18), boring1GroundTile);
	lisaBlock8.addObject(sf::Vector2i(0, 19), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(0, 20), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(0, 23), solidGroundTile);

	lisaBlock8.addObject(sf::Vector2i(1, 18), boring1GroundTile);
	lisaBlock8.addObject(sf::Vector2i(1, 19), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(1, 20), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock8.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock8.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock8.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock8.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock8.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock8.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock8.addObject(sf::Vector2i(5, 18), boring1GroundTile);
	lisaBlock8.addObject(sf::Vector2i(5, 19), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(5, 20), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(5, 23), solidGroundTile);

	lisaBlock8.addObject(sf::Vector2i(6, 18), boring1GroundTile);
	lisaBlock8.addObject(sf::Vector2i(6, 19), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(6, 20), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock8.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock8);

	ObjectBlock lisaBlock9 = {};
	lisaBlock9.addObject(sf::Vector2i(0, 7), platformTile);
	lisaBlock9.addObject(sf::Vector2i(1, 7), platformTile);
	lisaBlock9.addObject(sf::Vector2i(2, 7), platformTile);

	lisaBlock9.addObject(sf::Vector2i(2, 12), platformTile);
	lisaBlock9.addObject(sf::Vector2i(3, 12), platformTile);
	lisaBlock9.addObject(sf::Vector2i(4, 12), platformTile);

	lisaBlock9.addObject(sf::Vector2i(0, 2), platformTile);
	lisaBlock9.addObject(sf::Vector2i(1, 2), platformTile);
	lisaBlock9.addObject(sf::Vector2i(2, 2), platformTile);

	lisaBlock9.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock9.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(0, 23), solidGroundTile);

	lisaBlock9.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock9.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock9.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock9.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock9.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock9.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock9.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock9.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock9.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock9.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(5, 23), solidGroundTile);

	lisaBlock9.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock9.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock9.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock9);

	ObjectBlock lisaBlock10 = {};
	lisaBlock10.addObject(sf::Vector2i(0, 15), platformTile);
	lisaBlock10.addObject(sf::Vector2i(1, 15), platformTile);
	lisaBlock10.addObject(sf::Vector2i(2, 15), platformTile);

	lisaBlock10.addObject(sf::Vector2i(0, 20), boring1GroundTile);
	lisaBlock10.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(0, 23), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(1, 20), boring1GroundTile);
	lisaBlock10.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(1, 23), solidGroundTile);

	lisaBlock10.addObject(sf::Vector2i(2, 20), boring1GroundTile);
	lisaBlock10.addObject(sf::Vector2i(2, 21), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(2, 22), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(2, 23), solidGroundTile);

	lisaBlock10.addObject(sf::Vector2i(3, 20), boring1GroundTile);
	lisaBlock10.addObject(sf::Vector2i(3, 21), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(3, 22), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(3, 23), solidGroundTile);

	lisaBlock10.addObject(sf::Vector2i(4, 20), boring1GroundTile);
	lisaBlock10.addObject(sf::Vector2i(4, 21), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(4, 22), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(4, 23), solidGroundTile);

	lisaBlock10.addObject(sf::Vector2i(5, 20), boring1GroundTile);
	lisaBlock10.addObject(sf::Vector2i(5, 21), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(5, 22), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(5, 23), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(6, 20), boring1GroundTile);
	lisaBlock10.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock10.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock10);

	ObjectBlock lisaBlock11 = {};
	lisaBlock11.addObject(sf::Vector2i(4, 4), platformTile);
	lisaBlock11.addObject(sf::Vector2i(5, 4), platformTile);
	lisaBlock11.addObject(sf::Vector2i(6, 4), platformTile);

	lisaBlock11.addObject(sf::Vector2i(0, 17), boring1GroundTile);
	lisaBlock11.addObject(sf::Vector2i(0, 18), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(0, 19), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(0, 20), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(0, 21), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(0, 22), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(0, 23), solidGroundTile);

	lisaBlock11.addObject(sf::Vector2i(1, 17), boring1GroundTile);
	lisaBlock11.addObject(sf::Vector2i(1, 18), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(1, 19), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(1, 20), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(1, 21), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(1, 22), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(1, 23), solidGroundTile);


	lisaBlock11.addObject(sf::Vector2i(6, 19), boring1GroundTile);
	lisaBlock11.addObject(sf::Vector2i(6, 20), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(6, 21), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock11.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock11);

	ObjectBlock lisaBlock12 = {};
	lisaBlock12.addObject(sf::Vector2i(2, 7), platformTile);
	lisaBlock12.addObject(sf::Vector2i(3, 7), platformTile);
	lisaBlock12.addObject(sf::Vector2i(4, 7), platformTile);

	lisaBlock12.addObject(sf::Vector2i(4, 14), platformTile);
	lisaBlock12.addObject(sf::Vector2i(5, 14), platformTile);
	lisaBlock12.addObject(sf::Vector2i(6, 14), platformTile);
	generator.addBlock(lisaBlock12);

	ObjectBlock lisaBlock13 = {};
	lisaBlock13.addObject(sf::Vector2i(3, 4), platformTile);
	lisaBlock13.addObject(sf::Vector2i(4, 4), platformTile);
	lisaBlock13.addObject(sf::Vector2i(5, 4), platformTile);

	lisaBlock13.addObject(sf::Vector2i(3, 21), platformTile);
	lisaBlock13.addObject(sf::Vector2i(4, 21), platformTile);
	lisaBlock13.addObject(sf::Vector2i(5, 21), platformTile);
	generator.addBlock(lisaBlock13);

	ObjectBlock lisaBlock14 = {};
	lisaBlock14.addObject(sf::Vector2i(2, 24), platformTile);
	lisaBlock14.addObject(sf::Vector2i(3, 24), platformTile);
	lisaBlock14.addObject(sf::Vector2i(4, 24), platformTile);
	generator.addBlock(lisaBlock14);

	ObjectBlock lisaBlock15 = {};
	lisaBlock15.addObject(sf::Vector2i(2, 9), platformTile);
	lisaBlock15.addObject(sf::Vector2i(3, 9), platformTile);
	lisaBlock15.addObject(sf::Vector2i(4, 9), platformTile);

	lisaBlock15.addObject(sf::Vector2i(6, 21), boring1GroundTile);
	lisaBlock15.addObject(sf::Vector2i(6, 22), solidGroundTile);
	lisaBlock15.addObject(sf::Vector2i(6, 23), solidGroundTile);
	generator.addBlock(lisaBlock15);

	ObjectBlock wideGapBlock = {};
	wideGapBlock.addObject(sf::Vector2i(0, 21), boring1GroundTile);
	wideGapBlock.addObject(sf::Vector2i(0, 22), solidGroundTile);
	wideGapBlock.addObject(sf::Vector2i(0, 23), solidGroundTile);
	wideGapBlock.addObject(sf::Vector2i(1, 21), boring1GroundTile);
	wideGapBlock.addObject(sf::Vector2i(1, 22), solidGroundTile);
	wideGapBlock.addObject(sf::Vector2i(1, 23), solidGroundTile);

	wideGapBlock.addObject(sf::Vector2i(2, 15), platformTile);
	wideGapBlock.addObject(sf::Vector2i(3, 15), platformTile);
	wideGapBlock.addObject(sf::Vector2i(4, 15), platformTile);

	wideGapBlock.addObject(sf::Vector2i(5, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(6, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(7, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(8, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(9, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(10, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(11, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(12, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(13, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(14, 0), platformTile);
	wideGapBlock.addObject(sf::Vector2i(15, 0), platformTile);

	wideGapBlock.addObject(sf::Vector2i(15, 15), platformTile);
	wideGapBlock.addObject(sf::Vector2i(16, 15), platformTile);
	generator.addBlock(wideGapBlock);


	ObjectBlock wideGapBlock1 = {};
	wideGapBlock1.addObject(sf::Vector2i(2, 15), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(3, 15), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(4, 15), platformTile);

	wideGapBlock1.addObject(sf::Vector2i(5, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(6, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(7, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(8, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(9, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(10, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(11, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(12, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(13, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(14, 0), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(15, 0), platformTile);

	wideGapBlock1.addObject(sf::Vector2i(15, 12), platformTile);
	wideGapBlock1.addObject(sf::Vector2i(16, 12), platformTile);
	generator.addBlock(wideGapBlock1);


	generator.addStartBlock(plainGroundBlock);
	generator.addStartBlock(var1GroundBlock);
	generator.addStartBlock(var2GroundBlock);
}

#endif