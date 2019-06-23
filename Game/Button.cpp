#include "Button.h"


Button::Button() {
	this->state = ButtonState::DEFAULT;
	this->rect.setPosition(sf::Vector2f(0, 0));
	this->rect.setSize(sf::Vector2f(100.f, 25.f));

	if (!font.loadFromFile("GameAssets/Font/pixelated.ttf")) {
		std::cout << "can't load font" << "\n";
	}
	this->rect.setFillColor(sf::Color::Black);
}

Button::Button(float x, float y, float width, float height, std::string text, sf::Color defaultColor, sf::Color hoverColor, sf::Color activeColor) {
	this->state = ButtonState::DEFAULT;
	this->rect.setPosition(sf::Vector2f(x, y));
	this->rect.setSize(sf::Vector2f(width, height));
	
	if (!font.loadFromFile("GameAssets/Font/pixelated.ttf")) {
		std::cout << "can't load font" << "\n";
	}

	this->text.setFont(font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(18);

	this->defaultColor = defaultColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->text.setPosition(
		this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f),
		this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height + 7.f / 2.f)
	);
	
	this->rect.setFillColor(defaultColor);

}

void Button::SetFontWithText(const std::string& text, const sf::Font& font) {
	this->text.setFont(font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(18);
}

void Button::SetSizeAndPosition(float x, float y, float width, float height) {
	this->rect.setPosition(sf::Vector2f(x, y));
	this->rect.setSize(sf::Vector2f(width, height));
}

void Button::SetColors(const sf::Color& defaultColor, const sf::Color& hoverColor, const sf::Color& activeColor) {
	this->defaultColor = defaultColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
}

void Button::CenterText() {
	this->text.setPosition(
		this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f),
		this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height + 7.f / 2.f)
	);
}

void Button::Render(sf::RenderTarget& target) {
	target.draw(this->rect);
	target.draw(this->text);
}

void Button::Update(const sf::Vector2f mousePos) {
	// Idle
	this->state = ButtonState::DEFAULT;

	if (this->rect.getGlobalBounds().contains(mousePos)) {
		this->state = ButtonState::HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->state = ButtonState::PRESSED;

	}

	switch (this->state) {
	case ButtonState::DEFAULT:
		this->rect.setFillColor(this->defaultColor);
		break;

	case ButtonState::HOVER:
		this->rect.setFillColor(this->hoverColor);
		break;

	case ButtonState::PRESSED:
		this->rect.setFillColor(this->activeColor);
		break;

	default:
		this->rect.setFillColor(sf::Color::Red);
		break;
	}
}

const sf::Vector2f& Button::GetSize() const {
	return rect.getSize();
}

const bool Button::IsPressed() const {
	if (this->state == ButtonState::PRESSED)
		return true;

	return false;
}

Button::~Button() {
	
}

