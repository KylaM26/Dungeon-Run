#pragma once

#include <SFML/Graphics.hpp>
#include "Asset.h"
#include "Button.h"
#include "Player.h"
#include "MainMenu.h"

enum STATE {
	MENU = 0,
	GAMEPLAY
};

class Game {
private:
	STATE currentState;
	Player player;
	Asset testAsset;

	sf::RenderWindow* window;
	sf::Clock deltaClock;

	Button testButton;
	sf::Vector2f mousePositionInView;
public:
	float deltaTime;

	Game(sf::RenderWindow& window);

	void Initialize();
	void Update();
	void Draw();

	~Game();
};

