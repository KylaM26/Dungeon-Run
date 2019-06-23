#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Asset.h"
#include "Collider.h"

enum ButtonState {
	DEFAULT = 0,
	PRESSED,
	HOVER
};

class Button {
private:
	sf::RectangleShape rect;
	sf::Font font;
	sf::Text text;
	sf::Color defaultColor, hoverColor, activeColor;
	ButtonState state;
public:
	Button();
	Button(float x, float y, float width, float height, std::string text, sf::Color defaultColor, sf::Color hoverColor, sf::Color activeColor);
	
	void Render(sf::RenderTarget& target);
	void Update(const sf::Vector2f mousePos);

	void SetFontWithText(const std::string& text, const sf::Font& font);
	void SetSizeAndPosition(float x, float y, float width, float height);
	void SetColors(const sf::Color& defaultColor, const sf::Color& hoverColor, const sf::Color& activeColor);
	void CenterText();

	const sf::Vector2f& GetSize() const;
	const bool IsPressed() const;
	~Button();
};