#pragma once
#include "SFML/Graphics.hpp"
#include "Enemy.h"
#include <iostream>


class Monster : public Enemy
{
private:
	double health;
	double attackPower;
	float speed = .1;
	int range;
	sf::Sprite entity;
	sf::CircleShape SearchRadius;

public:

	Monster(sf::Sprite sprite)
	{
		entity = sprite;
	}

	virtual void draw(sf::RenderWindow& window) override{
		window.draw(SearchRadius); //show the area 
		window.draw(entity);
	}
	virtual void getPos(sf::Sprite* ply) override{
		player = ply;
	}

	virtual void getStates() override {

	}
	virtual bool PlayerInRange();


	virtual void findPlayer() override;

	~Monster();
};

