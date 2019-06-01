#include "Game.h"



Game::Game(sf::RenderWindow& window) {
	this->window = &window;
	player = Player("Player");
}

void Game::Initialize() {
	player.sprite.CreateAsset("GameAssets/Sprites/player.png");
}

void Game::Upadte() {
}

void Game::Draw() {
 	window->draw(player.sprite.GetSprite()); // Drawing his sprite
}

Game::~Game() {
}