#pragma once
#include "SFML/Graphics.hpp"

class Enemy
{

protected:
	enum States {
		Search, Chase, Attack
	};

	States state = Chase;
	bool mAlive = true;
	sf::Sprite* player;

public:

	//virtual void attack() = 0;
	virtual void findPlayer() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void getStates() = 0;
	virtual void getPos(sf::Sprite*) = 0;	
	virtual bool PlayerInRange() = 0;


	virtual ~Enemy();
};

