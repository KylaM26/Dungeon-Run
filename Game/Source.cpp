#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>




int main()
{
	sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "Platformer");

	sf::Texture texture;
	sf::Sprite sprite;

	if (!texture.loadFromFile("GameAssets/block.png")) {
		std::cout << "Yah";
	}

	sprite.setTexture(texture);

	auto position = sprite.getPosition();

	while (Window.isOpen()) {
		sf::Event event;

		if (Window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed){
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

		Window.clear();

		Window.draw(sprite);

		Window.display();
	}

	return 0;
}

