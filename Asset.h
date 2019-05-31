#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Asset {
	sf::Sprite sprite;
	sf::Texture texture;

public:
	Asset();
	void CreateAsset(std::string path);
	const sf::Sprite& GetSprite() const;
	~Asset();
};

