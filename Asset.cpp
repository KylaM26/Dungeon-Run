#include "Asset.h"

Asset::Asset() {

}

void Asset::CreateAsset(std::string path) {
	if (!texture.loadFromFile(path)) {
		std::cout << "Failed to load texture from file: " << path << std::endl;
	}

	sprite.setTexture(texture);
}

sf::Sprite& Asset::GetSprite() {
	return sprite;
}

Asset::~Asset() {

}
