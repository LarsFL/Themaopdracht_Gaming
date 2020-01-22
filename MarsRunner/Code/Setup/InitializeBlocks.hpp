#ifndef _INITALIZEBLOCKS_HPP
#define _INITALIZEBLOCKS_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Code/Game engine/World generation systems/GenerateBlock.hpp"
#include "Code/Game engine/World generation systems/ObjectBlock.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"

void generateBlocks(GenerateBlock& generator) {
	std::string futuristicPlatform = "../Assets/Objects/metalPlatforms.png";
	sf::IntRect futiristicPlatformRect = { 0, 0, 32, 16 };
	GameObject platform = { futuristicPlatform, sf::Vector2f(0,0), sf::Vector2f(1, 1), 5, true, futiristicPlatformRect, true };

	std::string groundLoc = "../Assets/Objects/ground.png";
	sf::IntRect groundVar1PlainRect = { 96, 0, 16, 16 };
	GameObject groundVar1Plain = { groundLoc, sf::Vector2f(0,0), sf::Vector2f(2,2), 5, true, groundVar1PlainRect, true };


	std::string test = "../Assets/Test/testplaatje.png";
	ObjectBlock testBlock = {};
	GameObject testObj{ test, sf::Vector2f(0,0), sf::Vector2f(.05,.05), 5 };
	testBlock.addObject(sf::Vector2i(1, 10), testObj);
	//generator.addBlock(testBlock);

	ObjectBlock test2Block = {};
	GameObject test2Obj{ test, sf::Vector2f(0,0), sf::Vector2f(.05, .05), 5 };
	test2Block.addObject(sf::Vector2i(3, 7), test2Obj);
	//generator.addBlock(test2Block);

	ObjectBlock platformBlock = {};
	platformBlock.addObject(sf::Vector2i(1, 10), platform);
	platformBlock.addObject(sf::Vector2i(2, 10), platform);
	platformBlock.addObject(sf::Vector2i(3, 10), platform);
	platformBlock.addObject(sf::Vector2i(0, 20), groundVar1Plain);
	platformBlock.addObject(sf::Vector2i(1, 20), groundVar1Plain);
	platformBlock.addObject(sf::Vector2i(2, 20), groundVar1Plain);
	platformBlock.addObject(sf::Vector2i(3, 20), groundVar1Plain);
	platformBlock.addObject(sf::Vector2i(4, 20), groundVar1Plain);
	generator.addBlock(platformBlock);

}

#endif