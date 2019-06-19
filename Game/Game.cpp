#include "Game.h"



Game::Game(sf::RenderWindow& window) {
	this->window = &window;
	player = Player("Player");
//	testButton = Button(window, sf::Vector2f(0, 0), sf::Vector2f(256, 256), "GameAssets/Sprites/ButtonTest.png");
}

void Game::Initialize() {
	player.sprite.CreateAsset("GameAssets/Sprites/player.png");
	testAsset.CreateAsset("GameAssets/Sprites/block.png");
	//sf::RectangleShape rect1;
	//rect1.setFillColor(sf::Color::Green);
	//rect1.setSize(sf::Vector2f(50.f, 50.f));
	//rect1.setPosition(50.f * 5.f, 50.f * 2.f);
	//rects.push_back(rect1);

}

void Game::Update() {	
	float moveSpeed = 6.f;
	sf::Event event;
	sf::Vector2f position = player.sprite.GetSprite().getPosition();
	player.MovePlayer(*window, event, position, player.sprite.GetSprite(), moveSpeed);
	
	player.sprite.LockToScreen(window);

	if (player.GetAsset().collider.IsCollidingWith(testAsset.GetSprite())) {
		std::cout << "Is colliding" << std::endl;
	} else {
		std::cout << "Is not colliding" << std::endl;
	}



}

void Game::Draw() {
 	window->draw(player.sprite.GetSprite()); // Drawing his sprite
	window->draw(testAsset.GetSprite());
	//for (sf::RectangleShape& i : rects) {
	//	window->draw(i);
	//}
}

Game::~Game() {
}