#ifndef _GENERATEBLOCK_HPP
#define _GENERATEBLOCK_HPP

#include <SFML/graphics.hpp>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "ObjectBlock.hpp"

class GenerateBlock {
private:
	std::vector<ObjectBlock> possibleBlocks;
public:
	GenerateBlock() {
		srand(time(NULL));
	};

	void addBlock(ObjectBlock& block) {
		possibleBlocks.push_back(block);
	}

	ObjectBlock generate() {
		return possibleBlocks[rand() % possibleBlocks.size()];;
	}
};

#endif