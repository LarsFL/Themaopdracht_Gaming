#ifndef _INITIALIZEANIMATIONS_HPP
#define _INITIALIZEANIMATIONS_HPP

#include <SFML/Graphics.hpp>

#include "../Game engine/Animation systems/Animation.hpp"
#include "../Game engine/Animation systems/AnimationStates.hpp"

void InitializePlayerAnimations(std::map<std::string, AnimationStates> &animationsMap) {
	AnimationStates smallAstronaut;
	
	//WALK
	sf::IntRect walkLoc (1,10, 22,33 ); //full frame: (1,1, 37,41)
	Animation Walking(walkLoc, 11, 39, 150); //was (walkLoc, 11, 39, 150)
	smallAstronaut.addAnimation(PossibleStates::WALK, Walking);

	//WALK_LEFT
	sf::IntRect walkLeftLoc(22, 10, -22, 33); //full frame: (1,1, -37,41)
	Animation WalkingLeft(walkLeftLoc, 11, 39, 75);
	smallAstronaut.addAnimation(PossibleStates::WALK_LEFT, WalkingLeft);
	
	//WALK_RIGHT
	sf::IntRect walkRightLoc(1, 10, 22, 33); //full frame: (1,1, 37,41)
	Animation WalkingRight(walkRightLoc, 11, 39, 75);
	smallAstronaut.addAnimation(PossibleStates::WALK_RIGHT, WalkingRight);

	//SHOOT
	sf::IntRect shootLoc(1,55 , 23, 33);
	Animation Shoot(shootLoc, 5, 39, 150, true, false, true);
	smallAstronaut.addAnimation(PossibleStates::SHOOT, Shoot);

	//IDLE
	sf::IntRect idleLoc(1, 99, 19, 34);
	Animation Idle(idleLoc, 8, 39, 150);
	smallAstronaut.addAnimation(PossibleStates::IDLE, Idle);

	//START SHOOT WALK
	sf::IntRect SSWLoc(1, 136, 37, 41);
	Animation Start_Shoot_Walk(SSWLoc, 2, 39, 150);
	smallAstronaut.addAnimation(PossibleStates::START_SHOOT_WALK, Start_Shoot_Walk);

	//JUMP START IMPACT
	sf::IntRect jstLoc(1, 190, 19, 33);
	Animation Jump_Start_Impact(jstLoc, 4, 39, 550, true, false, true); //jstLoc, 4, 39, 150, true, false, true)
	smallAstronaut.addAnimation(PossibleStates::JUMP_START_IMPACT, Jump_Start_Impact);

	//DAMAGED
	sf::IntRect damagedLoc(1, 316, 37, 41);
	Animation Damaged(damagedLoc, 4, 39, 150);
	smallAstronaut.addAnimation(PossibleStates::DAMAGED, Damaged);

	//DEATH
	sf::IntRect deathLoc(1, 361, 37, 41);
	Animation Death(deathLoc, 13, 39, 150, false);
	smallAstronaut.addAnimation(PossibleStates::DEATH, Death);

	animationsMap["player"] = smallAstronaut;
}


void InitializeSmallAlienAnimations(std::map<std::string, AnimationStates>& animationsMap) {
	AnimationStates smallAlien;
	
	//IDLE
	sf::IntRect idleLoc(581, 186, 18, 37); //569, 183, 30, 40
	Animation Idle(idleLoc, 8, 31, 150, true, true);
	smallAlien.addAnimation(PossibleStates::IDLE, Idle);

	//WALK
	sf::IntRect walkLoc(569, 227, 30, 40);
	Animation Walk(walkLoc, 9, 31, 150, true, true);
	smallAlien.addAnimation(PossibleStates::WALK, Walk);

	//ATTAC
	sf::IntRect attacLoc(569, 272, 30, 40);
	Animation Attac(attacLoc, 11, 31, 150, true, true);
	smallAlien.addAnimation(PossibleStates::SHOOT, Attac);

	//DEATH
	sf::IntRect deathLoc(569, 317, 30, 40);
	Animation Death(deathLoc, 16, 31, 150, false, true);
	smallAlien.addAnimation(PossibleStates::DEATH, Death);

	animationsMap["smallAlien"] = smallAlien;
}

void InitializeGreenAlienAnimations(std::map<std::string, AnimationStates>& animationsMap) {
	AnimationStates GreenAlien;

	//IDLE
	sf::IntRect idleLoc(7, 2, 18, 24);
	Animation Idle(idleLoc, 1, 32, 300);
	GreenAlien.addAnimation(PossibleStates::IDLE, Idle);

	//WALK (beetje raar)
	sf::IntRect walkLoc(7, 35, 18, 24);
	Animation Walk(walkLoc, 2, 32, 300);
	GreenAlien.addAnimation(PossibleStates::WALK, Walk);

	//DAMAGED
	sf::IntRect damagedLoc(7, 67, 18, 24);
	Animation Damaged(damagedLoc, 2, 32, 300);
	GreenAlien.addAnimation(PossibleStates::DAMAGED, Damaged);

	//DEATH
	sf::IntRect deathLoc(7, 99, 18, 24);
	Animation Death(deathLoc, 2, 32, 300, false);
	GreenAlien.addAnimation(PossibleStates::DEATH, Death);

	animationsMap["greenAlien"] = GreenAlien;
}

void InitializeSateliteAnimations(std::map<std::string, AnimationStates>& animationsMap) {
	AnimationStates satellite;

	//IDLE
	sf::IntRect idleLoc(10, 0, 92, 49);
	Animation Idle(idleLoc, 7, 121, 500);
	satellite.addAnimation(PossibleStates::IDLE, Idle);

	animationsMap["satellite"] = satellite;
}

#endif