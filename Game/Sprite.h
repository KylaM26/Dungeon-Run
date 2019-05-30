#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Sprite {
	 sf::Sprite sprite;
public:
	Sprite();
	Sprite(std::string path, int xOffset, int yOffset, int width, int height);
	void Scale(sf::Vector2f scale);
	void Position(sf::Vector2f position);
	const sf::Sprite& GetSprite() const;
	~Sprite();
};

