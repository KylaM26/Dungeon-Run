#include "Monster.h"



void Monster::findPlayer() {
	sf::Vector2f Playerposition = player.getPosition();
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
}



Monster::~Monster()
{
}
