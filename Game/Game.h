#pragma once
#include "Sprite.h"

class Game {
private:
	sf::RenderWindow* window;
	bool quit;
	Sprite test;
public:
	Game(sf::RenderWindow& w);

	void Initialize();
	void Update();
	void Draw();

	void SetQuit(bool q);

	const bool& GetQuit() const;
	~Game();
};

