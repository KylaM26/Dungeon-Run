#include "Game.h"

Game::Game(sf::RenderWindow& w) {
	window = &w;
	quit = false;
}


void Game:: Initialize() {
	test = Sprite("GameAssets/DungeonTileset.png", 16, 16, 16, 16);
}

void Game::Update() {

}

void Game::Draw() {
	window->draw(test.GetSprite());
}

const bool& Game::GetQuit() const {
	return quit;
}

void Game::SetQuit(bool q) {
	quit = q;
}

Game::~Game() {
}
