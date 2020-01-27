#ifndef _AUDIOMANAGER_HPP
#define _AUDIOMANAGER_HPP

#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>
#include <string>

class AudioManager {
private:
	std::map<std::string, sf::SoundBuffer> sounds;
	sf::Sound sound;
public:
	sf::Music music;
	AudioManager() {
		if (!music.openFromFile("../Assets/Audio/music.ogg")) {
			std::cout << "Failed to load music" << std::endl;
		}
		music.play();
		music.setLoop(true);
		sound.setVolume(70);
	}

	void addSound(std::string key, std::string location) {
		sf::SoundBuffer buffer;
		if (!buffer.loadFromFile(location)) {
			std::cout << "Failed to load sound with key: " << key << std::endl;
		}
		else {
			sounds[key] = buffer;
		}
	}

	void playSound(std::string key) {
		sound.setBuffer(sounds[key]);
		sound.play();
	}
};



#endif 