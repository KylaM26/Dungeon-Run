#pragma once

#include <SFML/Graphics.hpp>
#include "Asset.h"
#include "Button.h"
#include "Player.h"

class Game {
private:
	Player player;
	Asset testAsset;
	sf::RenderWindow* window;
	Button testButton;
//	std::vector<sf::RectangleShape> rects;
public:
	float deltaTime;

	Game(sf::RenderWindow& window);

	void Initialize();
	void Update();
	void Draw();

	~Game();
};

