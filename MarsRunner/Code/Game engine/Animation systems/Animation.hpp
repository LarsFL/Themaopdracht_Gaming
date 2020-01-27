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
	int timeToNextFrameInt;
	bool loop;
	bool backwards;
	bool blocking;

	int currentFrame = 0;

	bool busy = false;

public:
	//Animation(firstFrameLoc, nFrames, distToNextFrame, timeToNextFrameInt, loop, backwards, blokking
	Animation(sf::IntRect firstFrameLoc = { 0,0,0,0 }, int nFrames = 0, int distToNextFrame = 0, int timeToNextFrameInt = 0, bool loop = true, bool backwards = false, bool blokking = false) :
		firstFrameLoc(firstFrameLoc),
		nFrames(nFrames),
		distToNextFrame(distToNextFrame),
		timeToNextFrameInt(timeToNextFrameInt),
		loop(loop),
		backwards(backwards),
		blocking(blokking)
	{}

	Animation(const Animation& r):
		firstFrameLoc(r.firstFrameLoc),
		nFrames(r.nFrames),
		distToNextFrame(r.distToNextFrame),
		timeToNextFrameInt(r.timeToNextFrameInt),
		currentFrame(r.currentFrame),
		loop(r.loop),
		backwards(r.backwards),
		blocking(r.blocking)
	{}

	void goToNextFrame() {
		if (currentFrame == nFrames) {
			busy = false;
		}
		else {
			busy = true;
		}
		
		if (currentFrame + 1 <= nFrames) {
			currentFrame++;
			//busy = true;
		}
		else if(loop){
			currentFrame = 0;
			//busy = false;
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

	int getTimeToNextFrame() {
		return timeToNextFrameInt;
	}

	bool getBusy() {
		return busy;
	}

	bool getBlocking() {
		return blocking;
	}
};
#endif //_ANIMATION_HPP
