#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class Collider {
private:
	sf::Sprite* sprite;
public:
	Collider();
	Collider(sf::Sprite* spriteAsset);

	bool IsCollidingWith(sf::Sprite& sprite);
	bool IsCollidingWith(sf::RectangleShape& rect);


	~Collider();
};