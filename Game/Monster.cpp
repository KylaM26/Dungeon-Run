#include "Monster.h"

void Monster::patrol() {

	/*
		Change this to use acceleration
	*/

	Playerposition = player->sprite.getPosition();
	EntityPosition = entity.getPosition();

	if (PlayerInRange()) {
		state = Chase;
	}
	else {		
		int direction = RandomNum();
		switch (direction)
		{
		case North:
			EntityPosition.y += speed;
		case South:
			EntityPosition.y -= speed;
		case East:
			EntityPosition.x += speed;
		case West:
			EntityPosition.x -= speed;
		default:
			break;
		}
		entity.setPosition(EntityPosition);
	}
}

void Monster::findPlayer() {

	Playerposition = player->sprite.getPosition();
	EntityPosition = entity.getPosition();

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
		
	if (entity.getGlobalBounds().intersects(player->sprite.getGlobalBounds())) {
		state = Attack;
	}
}

bool Monster::PlayerInRange() {
	return SearchRadius.getGlobalBounds().intersects(player->sprite.getGlobalBounds());
}


void Monster::getStates() {
	switch (state)
	{

	case Patrol:
		patrol();
		break;

	case Chase:
		findPlayer();
		break;

	case Attack:
		attack();

	default:
		break;
	}
}




Monster::~Monster()
{
}
