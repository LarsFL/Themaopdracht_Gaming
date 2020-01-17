#ifndef _ANIMATIONSTATES_HPP
#define _ANIMATIONSTATES_HPP

#include <map>
#include <string>
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
	std::string currentAnimation;

	std::chrono::milliseconds timeToNextFrame;
	std::chrono::system_clock::time_point timeLastFrame;

	PossibleStates state = PossibleStates::IDLE;
public:
	AnimationStates(int timeToNextFrameInt){
		timeToNextFrame = timeToNextFrame;
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
		if (timeLastFrame + timeToNextFrame > current) {
			animations[state].goToNextFrame();
		}

		timeLastFrame = std::chrono::system_clock::now();
		return animations[state].getFrame();
	}
};
#endif