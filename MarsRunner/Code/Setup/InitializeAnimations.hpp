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


void InitializeSmallAlienAnimations(std::map<std::string, AnimationStates>& animationsMap) {
	AnimationStates smallAlien(150);
	
	//IDLE
	sf::IntRect idleLoc(569, 183, 30, 40);
	Animation Idle(idleLoc, 8, 31, true, true);
	smallAlien.addAnimation(PossibleStates::IDLE, Idle);

	//WALK
	sf::IntRect walkLoc(569, 227, 30, 40);
	Animation Walk(walkLoc, 9, 31, true, true);
	smallAlien.addAnimation(PossibleStates::WALK, Walk);

	//ATTAC
	sf::IntRect attacLoc(569, 272, 30, 40);
	Animation Attac(attacLoc, 11, 31, true, true);
	smallAlien.addAnimation(PossibleStates::SHOOT, Attac);

	//DEATH
	sf::IntRect deathLoc(569, 317, 30, 40);
	Animation Death(deathLoc, 16, 31, true, true);
	smallAlien.addAnimation(PossibleStates::DEATH, Death);

	animationsMap["smallAlien"] = smallAlien;
}

void InitializeGreenAlienAnimations(std::map<std::string, AnimationStates>& animationsMap) {
	AnimationStates GreenAlien(300);

	//IDLE
	sf::IntRect idleLoc(7, 2, 18, 24);
	Animation Idle(idleLoc, 1, 32);
	GreenAlien.addAnimation(PossibleStates::IDLE, Idle);

	//WALK (beetje raar)
	sf::IntRect walkLoc(7, 35, 18, 24);
	Animation Walk(walkLoc, 2, 32);
	GreenAlien.addAnimation(PossibleStates::WALK, Walk);

	//DAMAGED
	sf::IntRect damagedLoc(7, 67, 18, 24);
	Animation Damaged(damagedLoc, 2, 32);
	GreenAlien.addAnimation(PossibleStates::DAMAGED, Damaged);

	//DEATH
	sf::IntRect deathLoc(7, 99, 18, 24);
	Animation Death(deathLoc, 2, 32, false);
	GreenAlien.addAnimation(PossibleStates::DEATH, Death);

	animationsMap["greenAlien"] = GreenAlien;
}

void InitializeSateliteAnimations(std::map<std::string, AnimationStates>& animationsMap) {
	AnimationStates satellite(500);

	//IDLE
	sf::IntRect idleLoc(10, 0, 92, 49);
	Animation Idle(idleLoc, 7, 121);
	satellite.addAnimation(PossibleStates::IDLE, Idle);

	animationsMap["satellite"] = satellite;
}
#endif