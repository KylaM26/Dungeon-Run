#pragma once
#include <random>
#include <chrono>
#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"
#include "Player.h"


class Enemy
{

protected:
	
	typedef int States;

	States state = 0;
	bool mAlive = true;
	Player* player;
	double health;
	double attackPower;
	float speed = .1;
	int range;
	sf::Sprite entity;
	sf::CircleShape SearchRadius;

public:

	void getSpeed(double speed) {
		this->speed = speed;
	}

	int RandomNum() {
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine distribution(seed);

		std::uniform_int_distribution <int> random_number(0, 3);

		return random_number(distribution);
	}

	virtual void getStates() = 0;
	virtual void patrol() = 0;
	virtual bool PlayerInRange() = 0;
	virtual void findPlayer() = 0;
	virtual void attack() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void getPos(Player*) = 0;	


	virtual ~Enemy() { }
};

