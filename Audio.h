#pragma once

#include <SFML/Audio.hpp>

class Audio {
public:
	virtual void LoadSound(std::string path) = 0;
	virtual void Play() = 0;
};

class SoundEffect: public Audio {
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	SoundEffect() {}
	void LoadSound(std::string path) override {
		if (!buffer.loadFromFile(path)) {
			return;
		}
	}

	void Play() override {
		sound.setBuffer(buffer);
		sound.play();
	}

	~SoundEffect() {}
};


class Music : public Audio {
private:
	sf::Music buffer;
public:
	Music() {}
	void LoadSound(std::string path) override {
		if (!buffer.openFromFile("music.ogg")) {
			return;
		}
	}

	void Play() override {
		buffer.play();
	}

	~Music() {}
};