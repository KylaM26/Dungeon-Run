
#include "SFML/Graphics.hpp"
#include "Asset.h"
#include "Audio.h"
#include "Button.h"
#include "Game.h"
#include <windows.h>


void MovePlayer(sf::RenderWindow& Window, sf::Event& event, sf::Vector2f& position, sf::Sprite& sprite);

int main() {
	
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Dungeon Run");

	renderWindow.setKeyRepeatEnabled(true);
	
	Game game = Game(renderWindow);

	game.Initialize();

	while (renderWindow.isOpen())
	{
		game.Update();

		renderWindow.clear();
		game.Draw();
		renderWindow.display();
	}

}

sf::Font processFont() {
	sf::Font font;

	//Load and check the availability of the font file
	if (!font.loadFromFile("GameAssets/Font/pixelated.ttf"))
	{
		std::cout << "can't load font" << "\n";
	}

	return font;
}

void MovePlayer(sf::RenderWindow& Window, sf::Event& event, sf::Vector2f& position, sf::Sprite& sprite) {
	if (Window.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed) {
			Window.close();
		}
		if (event.type == sf::Event::EventType::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				position.y += 2;
				position.x += 2;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.y += 2;
				position.x -= 2;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				position.y -= 2;
				position.x += 2;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.y -= 2;
				position.x -= 2;
				sprite.setPosition(position);
			}



			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				position.y += 4;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				position.y -= 4;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.x -= 4;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				position.x += 4;
				sprite.setPosition(position);
			}
		}
	}
}