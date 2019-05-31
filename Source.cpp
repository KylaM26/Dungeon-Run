#include "SFML/Graphics.hpp"
#include "Asset.h"

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Dungeon Run");

	// Each asset will be loaded for each class.
	// Example:
	// The player will have his own asset,
	// The enemies will have a vector of assets since there will be multiple enemies.
	// So will a level class, (The surroundings and stuff like that.)
	// I will slice the rest of the sprites when we actually get started on the game.
	//  The Game class will do everything, this is just a test to see if it works.
	Asset test;
	test.CreateAsset("GameAssets/Player.png");

	sf::Event event;
	renderWindow.setKeyRepeatEnabled(true);

	while (renderWindow.isOpen())
	{

		while (renderWindow.pollEvent(event))
		{

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
					renderWindow.close();
				}
			}
			else if (event.type == sf::Event::EventType::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				}
			}

			renderWindow.clear();
			renderWindow.draw(test.GetSprite());
			renderWindow.display();
		}

		//delete game;
		//game = nullptr;
	}
}