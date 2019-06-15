#include "Player.h"


Player::Player() {
}

void Player::attack()
{

}

void Player::MovePlayer(sf::RenderWindow& Window, sf::Event& event, sf::Vector2f& position, sf::Sprite& sprite)
{
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

Player::~Player()
{
}
