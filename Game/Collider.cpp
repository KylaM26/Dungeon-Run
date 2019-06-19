#include "Collider.h"

Collider::Collider() {
	sprite = nullptr;
}

Collider::Collider(sf::Sprite* spriteAsset) {
	this->sprite = spriteAsset;
}

bool Collider::IsCollidingWith(sf::Sprite& sprite) {
	if (this->sprite->getGlobalBounds().intersects(sprite.getGlobalBounds())) {
		return true;
	}

	return false;
}

bool Collider::IsCollidingWith(sf::RectangleShape& rect) {
	if (sprite->getGlobalBounds().intersects(rect.getGlobalBounds())) {
		return true;
	}

	return false;
}

Collider::~Collider() {

}