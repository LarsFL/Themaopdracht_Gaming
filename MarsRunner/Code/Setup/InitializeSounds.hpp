#ifndef _INITIALIZESOUNDS_HPP
#define _INITIALIZESOUNDS_HPP

#include "Code/Game engine/Audio systems/AudioManager.hpp"

void initializeSounds(AudioManager& manager) {
    manager.addSound("pew", "../Assets/Audio/blaster1.ogg");
    manager.addSound("scream", "../Assets/Audio/wilhelm_scream.wav");
}


#endif