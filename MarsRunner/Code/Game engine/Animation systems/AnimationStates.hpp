#ifndef _ANIMATIONSTATES_HPP
#define _ANIMATIONSTATES_HPP

#include <map>
#include <string>
#include <iostream>
#include <chrono>

#include "Animation.hpp"

enum PossibleStates {
	CROUCH,
	DAMAGED,
	DEATH,
	IDLE,
	JUMP_START_IMPACT,
	SHOOT,
	START_SHOOT_WALK,
	WALK
};

class AnimationStates {
private:
	std::map<PossibleStates, Animation> animations = {};
	int nAnimations = 0;
	std::string currentAnimation = "";

	int timeToNextFrameInt = 0;
	std::chrono::system_clock::time_point timeLastFrame;

	PossibleStates state = PossibleStates::IDLE;
public:
	AnimationStates() {
		timeLastFrame = std::chrono::system_clock::now();
		std::cout << "Default constructor" << std::endl;
	}

	AnimationStates(int timeToNextFrameInt) :
		timeToNextFrameInt(timeToNextFrameInt)
	{
		std::cout << "Normal constructor" << std::endl;
	}

	AnimationStates(const AnimationStates& r) :
		animations(r.animations),
		nAnimations(r.nAnimations),
		currentAnimation(r.currentAnimation),
		timeToNextFrameInt(r.timeToNextFrameInt),
		timeLastFrame(r.timeLastFrame),
		state(r.state)
	{
		std::cout << "Copy constructor" << std::endl;
	}

	void addAnimation(PossibleStates state, Animation newAnimation) {
		animations[state] = newAnimation;
		nAnimations++;
	}

	void setState(PossibleStates newState) {
		state = newState;
	}

	Animation getAnimation() {
		return animations[state];
	}

	sf::IntRect getFrame() {
		auto current = std::chrono::system_clock::now();

		auto temp = std::chrono::duration_cast<std::chrono::milliseconds>(current - timeLastFrame);
		if(temp.count() > timeToNextFrameInt){
			animations[state].goToNextFrame();
			timeLastFrame = std::chrono::system_clock::now();
		}

		std::cout << state << std::endl;
		return animations[state].getFrame();
	}
};
#endif