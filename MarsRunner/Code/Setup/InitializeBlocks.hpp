#ifndef _INITALIZEBLOCKS_HPP
#define _INITALIZEBLOCKS_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Code/Game engine/World generation systems/GenerateBlock.hpp"
#include "Code/Game engine/World generation systems/ObjectBlock.hpp"
#include "Code/Game engine/Object systems/GameObject.hpp"

void generateBlocks(GenerateBlock& generator) {

	std::string test = "../Assets/Test/testplaatje.png";
	ObjectBlock testBlock = {};
	GameObject testObj{ test, sf::Vector2f(0,0), sf::Vector2f(.05,.05), 5 };
	testBlock.addObject(sf::Vector2i(1, 10), testObj);
	generator.addBlock(testBlock);

}

#endif