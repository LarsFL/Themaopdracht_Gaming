#ifndef _ANIMATIONSTATES_HPP
#define _ANIMATIONSTATES_HPP

#include <map>
#include <string>

#include "Animation.hpp"

class animationStates {
private:
	std::map<std::string, Animation> animations = {};
	int nAnimations = 0;
	std::string currentAnimation;
public:
	animationStates(){}

	void addAnimation(std::string name, Animation newAnimation) {
		animations[name] = newAnimation;
		nAnimations++;
	} 

	void setAnimation(std::string newAnimation) {
		if (animations.find(newAnimation) == animations.end()) {
			//error
		}
		else {
			currentAnimation = newAnimation;
		}
	}

	Animation getAnimation() {
		return animations[currentAnimation];
	}
};
#endif