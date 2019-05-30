#include "SFML/Graphics.hpp"
//#include "Game.h"

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Dungeon Run");

	sf::Texture texture;

	texture.loadFromFile("GameAssets/DungeonTileset.png");

	sf::Sprite sprite(texture);

	sf::Event event;
	renderWindow.setKeyRepeatEnabled(true);

	//Game* game = new Game(renderWindow);

	//game->Initialize();

	while (renderWindow.isOpen())
	{

		while (renderWindow.pollEvent(event))
		{
			//game->Update();

			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}

			//set window to random color to check if working
			if (event.type == sf::Event::EventType::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				}
			}
			else if (event.type == sf::Event::EventType::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				}
			}

			//game->Draw();
			renderWindow.clear();
			renderWindow.draw(sprite);
			renderWindow.display();
		}

		//delete game;
		//game = nullptr;
	}
}