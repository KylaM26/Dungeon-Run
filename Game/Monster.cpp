#include "Monster.h"



void Monster::findPlayer() {
	sf::Vector2f Playerposition = player->getPosition();
	sf::Vector2f EntityPosition = entity.getPosition();

		if (Playerposition.x > EntityPosition.x) {
			EntityPosition.x += speed;
		}
		if (Playerposition.y > EntityPosition.y) {
			EntityPosition.y += speed;
		}
		if (Playerposition.x < EntityPosition.x) {
			EntityPosition.x -= speed;
		}
		if (Playerposition.y < EntityPosition.y) {
			EntityPosition.y -= speed;
		}
		entity.setPosition(EntityPosition);
		
		if (entity.getGlobalBounds().intersects(player->getGlobalBounds())) {
			
		}
}

bool Monster::PlayerInRange() {
	auto pos = entity.getGlobalBounds();
	auto center = entity.getPosition();

	SearchRadius.setRadius(pos.height);
	SearchRadius.setPosition(center.x - 32 ,center.y - 32); // center image in circle

	return SearchRadius.getGlobalBounds().intersects(player->getGlobalBounds());
}

/*
void Enemy::getStates() {
		switch (state)
		{

		case Enemy::Search:
			if (PlayerInRange()) state = Chase;
			break;

		case Enemy::Chase:
			findPlayer();
			break;

		case Enemy::Attack:
			attack();

		default:
			break;
		}
}
*/



Monster::~Monster()
{
}
