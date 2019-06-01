#pragma once
#include <string>

class Player
{
public:
	Player(std::string name) 
		: name(name) 
	{

	}

	std::string name = "";
	double health = 100;
	double stamina = 100;
	int level = 1;

	void attack();

	~Player();
};

