#ifndef _ANIMATIONSTATES_HPP
#define _ANIMATIONSTATES_HPP

#include <map>
#include <string>
#include <iostream>
#include <chrono>

#include "Animation.hpp"

enum class PossibleStates {
	CROUCH,
	DAMAGED,
	DEATH,
	IDLE,
	JUMP_START_IMPACT,
	SHOOT,
	START_SHOOT_WALK,
	WALK,
	WALK_LEFT,
	WALK_RIGHT
};

class AnimationStates {
private:
	std::map<PossibleStates, Animation> animations = {};
	int nAnimations = 0;
	std::string currentAnimation = "";

	std::chrono::system_clock::time_point timeLastFrame;

	PossibleStates tempState = PossibleStates::IDLE;

	PossibleStates state = PossibleStates::IDLE;

	float gameSpeed = 0.f;

	bool paused = 0;

public:
	AnimationStates() {
		timeLastFrame = std::chrono::system_clock::now();
		std::cout << "Default constructor" << std::endl;
	}

	AnimationStates(const AnimationStates& r) :
		animations(r.animations),
		nAnimations(r.nAnimations),
		currentAnimation(r.currentAnimation),
		timeLastFrame(r.timeLastFrame),
		state(r.state)
	{
		std::cout << "Copy constructor" << std::endl;
	}

	void addAnimation(PossibleStates state, Animation &newAnimation) {
		animations[state] = newAnimation;
		nAnimations++;
	}

	void setState(PossibleStates newState) {
		tempState = newState;
	}

	Animation getAnimation() {
		return animations[state];
	}

	sf::IntRect getFrame() {
		//std::cout << paused << std::endl;
		if (!paused) {

			auto current = std::chrono::system_clock::now();

			if (animations[state].getBlocking() ) {
				if (!animations[state].getBusy() ) {
					state = tempState;
				}
			}
			else{
				state = tempState;
			}

			auto temp = std::chrono::duration_cast<std::chrono::milliseconds>(current - timeLastFrame);
			if(temp.count() > animations[state].getTimeToNextFrame() - (gameSpeed * 30)){
				animations[state].goToNextFrame();
				timeLastFrame = std::chrono::system_clock::now();
			}
		}

		return animations[state].getFrame();
	}

	bool getBusy() {
		return animations[tempState].getBusy();
	}
	bool getBlocking() {
		return animations[tempState].getBlocking();
	}

	void setGameSpeed(float newGameSpeed) {
		gameSpeed = newGameSpeed;
	}

	void setPaused(bool newValue) {
		paused = newValue;
	}
};
#endif