#ifndef _ANIMATION_HPP
#define _ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
private:
	int fps;

	std::vector <sf::IntRect> FrameLoctations = {};
	int nFrames = 0;
	int currentFrame = 0;

public:
	Animation(int fps) :
		fps(fps)
	{}

	void addFrameLoctation(sf::IntRect newLocation) {
		FrameLoctations.push_back(newLocation);
		nFrames++;
	}

	void setFirstFrame(sf::Sprite& sprite) {
		currentFrame = 0;
		sprite.setTextureRect(FrameLoctations[currentFrame]);
	}

	void goToNextFrame(sf::Sprite& sprite) {
		if (currentFrame + 1 < nFrames) {
			currentFrame++;
		}
		else {
			currentFrame = 0;
		}
		sprite.setTextureRect(FrameLoctations[currentFrame]);
	}
};
#endif //_ANIMATION_HPP
