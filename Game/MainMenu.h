#pragma once

#include "Button.h"
#include "Asset.h"
#include "GameSaver.h"

class MainMenu {
private:
	Asset background;
	sf::Text titleText;
	sf::Font font;
	MainMenu() {}
	MainMenu(const MainMenu& menu) {}
	const MainMenu& operator= (MainMenu&) {}
	Button startGameBtn; // = Button(titleText.getPosition().x, titleText.getPosition().y + 40.f, 128.f, 32.f, "New Game", sf::Color(129, 43, 160), sf::Color::Red, sf::Color::Yellow);
	Button loadGameBtn; // = Button(titleText.getPosition().x, titleText.getPosition().y + 80.f, 128.f, 32.f, "Load Game", sf::Color(129, 43, 160), sf::Color::Red, sf::Color::Yellow);

public:

	static MainMenu& Instance() {
		static MainMenu menu = MainMenu();
		return menu;
	}

	void Update(const sf::Vector2f& mousePos);
	void Initialize(const sf::Vector2f& windowSize);
	void Render(sf::RenderWindow* window);
	void GetSavedGames();

	const bool& DidStartGame() const;
	const bool& DidLoadGame() const;
	~MainMenu();
};

