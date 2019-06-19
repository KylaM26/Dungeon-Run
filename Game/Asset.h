#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Collider.h"

class Asset {
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Collider collider;
	Asset();

	void CreateAsset(std::string path);
	void LockToScreen(sf::RenderWindow* window);
	sf::Sprite& GetSprite();
	sf::Texture& GetTexture();
	~Asset();
};

