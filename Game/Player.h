#pragma once
#include <string>

#include "Asset.h"

class Player
{
public:
	Player();
	Player(std::string name)
		: name(name)
	{
	}


	std::string name = "";
	double health = 100;
	double stamina = 100;
	int level = 1;
	Asset sprite;

	void attack();
	void MovePlayer(sf::RenderWindow& Window, sf::Event& event, sf::Vector2f& position, sf::Sprite& sprite);

	~Player();
};

