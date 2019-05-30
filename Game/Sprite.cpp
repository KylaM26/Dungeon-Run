#include "Sprite.h"


Sprite::Sprite() { }

Sprite::Sprite(std::string path, int xOffset, int yOffset, int width, int height) {

	sf::Texture texture = sf::Texture();
	
	if (!texture.loadFromFile(path, sf::IntRect(xOffset, yOffset, width, height))) {
		std::cout << "Failed to load image: " << path << std::endl;
		return;
	}

	sprite.setTexture(texture);
}

void Sprite::Position(sf::Vector2f position) {
	sprite.setPosition(position);
}

void Sprite::Scale(sf::Vector2f scale) {
	sprite.setScale(scale);
}


const sf::Sprite& Sprite::GetSprite() const {
	return sprite;
}

Sprite::~Sprite() {}