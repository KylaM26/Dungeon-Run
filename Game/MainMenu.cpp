#include "MainMenu.h"

void MainMenu::Initialize(const sf::Vector2f& windowSize) {
	background.CreateAsset("GameAssets/Sprites/Tile2.png");
	sf::Vector2f backgroundScale = sf::Vector2f(
		(float)windowSize.x / background.GetTexture().getSize().x,
		(float)windowSize.y / background.GetTexture().getSize().y);
	
	background.GetSprite().setScale(backgroundScale);

	if (!font.loadFromFile("GameAssets/Font/pixelated.ttf")) {
		std::cout << "Failed to load font for menu" << std::endl;
	}

	titleText.setFont(font);
	titleText.setString("Dungeon Run");
	titleText.setFillColor(sf::Color::White);
	titleText.setCharacterSize(60);
	titleText.setPosition(sf::Vector2f((windowSize.x / 2) - (titleText.getGlobalBounds().width / 2), (windowSize.y / 2) - (titleText.getGlobalBounds().height / 2) - 170.f));

	startGameBtn.SetSizeAndPosition(titleText.getPosition().x + (startGameBtn.GetSize().x / 2), titleText.getPosition().y + 120.f, 128.f, 32.f);
	loadGameBtn.SetSizeAndPosition(titleText.getPosition().x + (loadGameBtn.GetSize().x / 2), titleText.getPosition().y + 180.f, 128.f, 32.f);

	startGameBtn.SetFontWithText("New Game", font);
	loadGameBtn.SetFontWithText("Load Game", font);

	startGameBtn.SetColors(sf::Color(129, 43, 160), sf::Color::Red, sf::Color::Yellow);
	loadGameBtn.SetColors(sf::Color(129, 43, 160), sf::Color::Red, sf::Color::Yellow);

	startGameBtn.CenterText();
	loadGameBtn.CenterText();

}

void MainMenu::Update(const sf::Vector2f& mousePos) {
	startGameBtn.Update(mousePos);
	loadGameBtn.Update(mousePos);
		
}

void MainMenu::Render(sf::RenderWindow* window) {
	window->draw(background.GetSprite());
	window->draw(titleText);
	 startGameBtn.Render(*window);
	 loadGameBtn.Render(*window);
}

void GetSavedGames() {

}

const bool& MainMenu::DidStartGame() const {
	return startGameBtn.IsPressed();
}

const bool& MainMenu::DidLoadGame() const {
	return loadGameBtn.IsPressed();
}

MainMenu::~MainMenu() {

}