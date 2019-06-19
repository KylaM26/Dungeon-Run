#include "Asset.h"

Asset::Asset() {
}

void Asset::CreateAsset(std::string path) {
	if (!texture.loadFromFile(path)) {
		std::cout << "Failed to load texture from file: " << path << std::endl;
	}

	sprite.setTexture(texture);
	collider = Collider(&sprite);
}

void Asset::LockToScreen(sf::RenderWindow* window) {
	if (sprite.getPosition().x < 0.f) {
		sprite.setPosition(0.f, sprite.getPosition().y);
	}

	if (sprite.getPosition().y < 0.f) {
		sprite.setPosition(sprite.getPosition().x, 0.f);
	}

	if (sprite.getPosition().x + sprite.getGlobalBounds().width > window->getSize().x) {
		sprite.setPosition(window->getSize().x - sprite.getGlobalBounds().width, sprite.getPosition().x);
	}

	if (sprite.getPosition().y + sprite.getGlobalBounds().width > window->getSize().y) {
		sprite.setPosition(sprite.getPosition().x, window->getSize().y - sprite.getGlobalBounds().height);
	}
}

sf::Sprite& Asset::GetSprite() {
	return sprite;
}

sf::Texture& Asset::GetTexture() {
	return texture;
}


Asset::~Asset() {

}
