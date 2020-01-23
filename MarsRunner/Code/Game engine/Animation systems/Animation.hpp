#ifndef _ANIMATION_HPP
#define _ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>
class Animation {
private:
	sf::IntRect firstFrameLoc; //left, top, width, height
	int nFrames;
	int distToNextFrame;

	int currentFrame = 0;

	bool loop;
	bool backwards;

public:

	Animation(sf::IntRect firstFrameLoc = { 0,0,0,0 }, int nFrames = 0, int distToNextFrame = 0, bool loop = true, bool backwards = false) :
		firstFrameLoc(firstFrameLoc),
		nFrames(nFrames),
		distToNextFrame(distToNextFrame),
		loop(loop),
		backwards(backwards)
	{}

	Animation(const Animation& r):
		firstFrameLoc(r.firstFrameLoc),
		nFrames(r.nFrames),
		distToNextFrame(r.distToNextFrame),
		currentFrame(r.currentFrame),
		loop(r.loop),
		backwards(r.backwards)
	{}

	void goToNextFrame() {
		if (currentFrame + 1 <= nFrames) {
			currentFrame++;
		}
		else if(loop){
			currentFrame = 0;
		}
	}

	sf::IntRect getFrame() {
		if (backwards) {
			sf::IntRect currentFrameRect = firstFrameLoc;
			currentFrameRect.left -= (distToNextFrame * currentFrame);

			return currentFrameRect;
		}
		else {
			sf::IntRect currentFrameRect = firstFrameLoc;
			currentFrameRect.left += (distToNextFrame * currentFrame);

			return currentFrameRect;
		}
	}
};
#endif //_ANIMATION_HPP
