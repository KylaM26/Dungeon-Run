//#define SFML_DYNAMIC

#include "SFML/Graphics.hpp"

#include <iostream>
#include "Game.h"

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Dungeon Run");

	while (renderWindow.isOpen())
	{
		sf::Event event;
		Game* game = new Game(renderWindow);

		game->Initialize();

		while (renderWindow.pollEvent(event))
		{
			game->Update();

			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}

			renderWindow.clear(sf::Color::White);

			game->Draw();

			renderWindow.display();
		}

		delete game;
		game = nullptr;
	}
}