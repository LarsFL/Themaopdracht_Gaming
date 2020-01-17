#ifndef _ANIMATION_HPP
#define _ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
private:
	sf::IntRect firstFrameLoc; //left, top, width, height
	int nFrames;
	int distToNextFrame;

	int currentFrame = 0;

public:
	Animation(sf::IntRect firstFrameLoc = { 0,0,0,0 }, int nFrames = 0, int distToNextFrame = 0) :
		firstFrameLoc(firstFrameLoc),
		nFrames(nFrames),
		distToNextFrame(distToNextFrame)
	{}

	void goToNextFrame() {
		if (currentFrame + 1 < nFrames) {
			currentFrame++;
		}
		else {
			currentFrame = 0;
		}
	}

	sf::IntRect getFrame() {
		sf::IntRect currentFrameRect = firstFrameLoc;
		currentFrameRect.left += (distToNextFrame * currentFrame);
		return currentFrameRect;
	}
};
#endif //_ANIMATION_HPP
