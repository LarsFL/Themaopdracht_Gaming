#ifndef _INITIALIZEANIMATIONS_HPP
#define _INITIALIZEANIMATIONS_HPP

#include <SFML/Graphics.hpp>

#include "../Game engine/Animation systems/Animation.hpp"
#include "../Game engine/Animation systems/AnimationStates.hpp"

void InitializePlayerAnimations(std::map<std::string, AnimationStates> &animationsMap) {
	AnimationStates smallAstronaut(150);
	
	//WALK
	sf::IntRect walkLoc (1,1, 37,41 );
	Animation Walking(walkLoc, 11, 39);
	smallAstronaut.addAnimation(PossibleStates::WALK, Walking);

	//SHOOT
	sf::IntRect shootLoc(1,46 , 37, 41);
	Animation Shoot(shootLoc, 5, 39);
	smallAstronaut.addAnimation(PossibleStates::SHOOT, Shoot);

	//IDLE
	sf::IntRect idleLoc(1, 91, 37, 41);
	Animation Idle(idleLoc, 8, 39);
	smallAstronaut.addAnimation(PossibleStates::IDLE, Idle);

	//START SHOOT WALK
	sf::IntRect SSWLoc(1, 136, 37, 41);
	Animation Start_Shoot_Walk(SSWLoc, 2, 39);
	smallAstronaut.addAnimation(PossibleStates::START_SHOOT_WALK, Start_Shoot_Walk);

	//JUMP START IMPACT
	sf::IntRect jstLoc(1, 181, 37, 41);
	Animation Jump_Start_Impact(jstLoc, 4, 39);
	smallAstronaut.addAnimation(PossibleStates::JUMP_START_IMPACT, Jump_Start_Impact);

	//DAMAGED
	sf::IntRect damagedLoc(1, 316, 37, 41);
	Animation Damaged(damagedLoc, 4, 39);
	smallAstronaut.addAnimation(PossibleStates::DAMAGED, Damaged);

	//DEATH
	sf::IntRect deathLoc(1, 361, 37, 41);
	Animation Death(deathLoc, 13, 39, false);
	smallAstronaut.addAnimation(PossibleStates::DEATH, Death);

	animationsMap["player"] = smallAstronaut;
} 
#endif