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

public:

	sf::Sprite entity;

	Monster(sf::Sprite sprite)
	{
		entity = sprite;
	}

	virtual void draw(sf::RenderWindow& window) override{
		window.draw(entity);
	}
	virtual void getPos(sf::Sprite* ply) override{
		player = *ply;
	}

	virtual void getStates() override {

	}


	virtual void findPlayer() override;

	~Monster();
};

