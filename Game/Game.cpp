#include "Game.h"



Game::Game(sf::RenderWindow& window) {
	this->window = &window;
	player = Player("Player");
	currentState = STATE::MENU;
}

void Game::Initialize() {
	player.sprite.CreateAsset("GameAssets/Sprites/player.png");
	testAsset.CreateAsset("GameAssets/Sprites/block.png");
	MainMenu::Instance().Initialize((sf::Vector2f)window->getSize());

}

void Game::Update() {	
	sf::Time dt = deltaClock.restart();
	mousePositionInView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

	switch (currentState) {
	case STATE::MENU: {
		MainMenu::Instance().Update(mousePositionInView);

		if (MainMenu::Instance().DidStartGame())
			currentState = STATE::GAMEPLAY;
	} break;

	case STATE::GAMEPLAY: {
		float moveSpeed = 6.f;
		sf::Event event;
		sf::Vector2f position = player.sprite.GetSprite().getPosition();
		player.MovePlayer(*window, event, position, player.sprite.GetSprite(), moveSpeed * dt.asMilliseconds());

		player.sprite.LockToScreen(window);
	} break;

	}

}

void Game::Draw() {
	switch (currentState) {
	case STATE::MENU: {
		MainMenu::Instance().Render(window);
	} break;

	case STATE::GAMEPLAY: {
		window->draw(player.sprite.GetSprite()); // Drawing his sprite
		window->draw(testAsset.GetSprite());
	} break;
	}

}

Game::~Game() {
}