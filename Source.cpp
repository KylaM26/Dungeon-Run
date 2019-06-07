#include "SFML/Graphics.hpp"
#include "Asset.h"
#include "Audio.h"
#include "Game.h"

sf::Font processFont();

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Dungeon Run");
	SoundEffect death;
	death.LoadSound("GameAssets/Sounds/PlayerDeath.wav");
	// Each asset will be loaded for each class.
	// Example:
	// The player will have his own asset,
	// The enemies will have a vector of assets since there will be multiple enemies.
	// So will a level class, (The surroundings and stuff like that.)
	// I will slice the rest of the sprites when we actually get started on the game.
	//  The Game class will do everything, this is just a test to see if it works.
	//Asset test;
	//test.CreateAsset("GameAssets/Player.png");

	sf::Event event;
	renderWindow.setKeyRepeatEnabled(true);

	Game game = Game(renderWindow);

	game.Initialize(); // Any thing we should initialize should go here or in the game constuctor.
	while (renderWindow.isOpen()) 
	{

		while (renderWindow.pollEvent(event))
		{

			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}

			game.Upadte();
			//set window to random color to check if working
			if (event.type == sf::Event::EventType::KeyPressed) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					death.Play();
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
			game.Draw();
			renderWindow.display();
		}
	}
}

sf::Font processFont() 
{
	sf::Font font;

	//Load and check the availability of the font file
	if (!font.loadFromFile("GameAssets/Font/pixelated.ttf"))
	{
		std::cout << "can't load font" << "\n";
	}

	return font;
}
