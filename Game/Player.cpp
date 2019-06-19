#include "Player.h"


Player::Player() {

}

void Player::attack()
{
	
}
void Player::MovePlayer(sf::RenderWindow& Window, sf::Event& event, sf::Vector2f& position, sf::Sprite& sprite, float speed) {

	if (Window.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed) {
			Window.close();
		}

		if (event.type == sf::Event::EventType::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		/*		position.y += (speed * deltaTime) / 2.f;
				position.x += (speed * deltaTime) / 2.f;*/

				position.y += speed;
				position.x += speed;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.y += speed;
				position.x -= speed;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				position.y -= speed;
				position.x += speed;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.y -= speed;
				position.x -= speed;
				sprite.setPosition(position);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				position.y += speed;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				position.y -= speed;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				position.x -= speed;
				sprite.setPosition(position);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				position.x += speed;
				sprite.setPosition(position);
			}
		}
	}
}


Asset& Player::GetAsset() {
	return sprite;
}

Player::~Player()
{
}
