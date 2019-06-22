#pragma once
#include "SFML/Graphics.hpp"
#include "Enemy.h"
#include <iostream>


class Monster : public Enemy
{
private:
	sf::Vector2f Playerposition;
	sf::Vector2f EntityPosition;

	enum States {
		Patrol, Chase, Attack
	};
	enum directions{
		North, South, East, West
	};

public:

	Monster(sf::Sprite sprite)
	{
		entity = sprite;
	}

	virtual void patrol() override;

	virtual void attack() override {
		player->health -= 5;
		if (!PlayerInRange()){
			state = Chase;
		}
	}

	virtual void draw(sf::RenderWindow& window) override{

		auto pos = entity.getGlobalBounds();
		auto center = entity.getPosition();
		SearchRadius.setRadius(pos.height);
		SearchRadius.setPosition(center.x - 32, center.y - 32); // center image in circle

		window.draw(SearchRadius); //show the area 
		window.draw(entity);
	}
	virtual void getPos(Player* ply) override{
		player = ply;
	}

	virtual void getStates() override;

	virtual bool PlayerInRange();

	virtual void findPlayer() override;

	~Monster();
};

