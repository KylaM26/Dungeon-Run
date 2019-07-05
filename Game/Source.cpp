
#include "SFML/Graphics.hpp"
#include "Asset.h"
#include "Audio.h"
#include "Button.h"
#include "Game.h"

#include "PositionParser.h"

void MovePlayer(sf::RenderWindow& Window, sf::Event& event, sf::Vector2f& position, sf::Sprite& sprite);

int main() {

	std::vector<sf::Vector2i> pos;
	pos.push_back(sf::Vector2i(1393, 8594));
	pos.push_back(sf::Vector2i(3, 4));
	pos.push_back(sf::Vector2i(44, 948));
	pos.push_back(sf::Vector2i(93, 43));
	pos.push_back(sf::Vector2i(84983943, 4332));

	PositionParser::Instance().SaveToFile("Position.txt", pos);

	std::vector<sf::Vector2i> positions = PositionParser::Instance().ReadFile("Position.txt");

	for (int index = 0; index < positions.size(); index++) {
		std::cout << positions.at(index).x << ", " << positions.at(index).y << std::endl;
	}


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