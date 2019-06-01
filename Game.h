#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

class Game {
private:
	Player player;
	sf::RenderWindow* window;
public:
	Game(sf::RenderWindow& window);

	void Initialize();
	void Upadte();
	void Draw();

	~Game();
};

