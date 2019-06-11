#include "Button.h"


Button::Button() {

}

Button::Button(float x, float y, float width, float height, std::string text, sf::Color defaultColor, sf::Color hoverColor, sf::Color activeColor) {
	this->state = ButtonState::DEFAULT;
	this->rect.setPosition(sf::Vector2f(x, y));
	this->rect.setSize(sf::Vector2f(width, height));
	
	if (!font.loadFromFile("GameAssets/Font/pixelated.ttf"))
	{
		std::cout << "can't load font" << "\n";
	}

	this->text.setString(text);
	//this->text.setColor(sf::Color::White);
	this->text.setCharacterSize(12);

	this->defaultColor = defaultColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->text.setPosition(this->rect.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f, this->rect.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f);

	this->rect.setFillColor(defaultColor);
}

void Button::Render(sf::RenderTarget& target) {
	target.draw(this->rect);
}

void Button::Update(const sf::Vector2f mousePos) {
	// Idle
	this->state = ButtonState::DEFAULT;

	if (this->rect.getGlobalBounds().contains(mousePos)) {
		this->state = ButtonState::HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->state = ButtonState::PRESSED;

	} else {
		std::cout << "Does not contain." << std::endl;
	}

	switch (this->state) {
	case ButtonState::DEFAULT:
//		std::cout << "Default" << std::endl;
		this->rect.setFillColor(this->defaultColor);
		break;

	case ButtonState::HOVER:
		std::cout << "Hover" << std::endl;
		this->rect.setFillColor(this->hoverColor);
		break;

	case ButtonState::PRESSED:
		std::cout << "Pressed" << std::endl;
		this->rect.setFillColor(this->activeColor);
		break;

	default:
		this->rect.setFillColor(sf::Color::Red);
		break;
	}
}

const bool Button::IsPressed() const {
	if (this->state == ButtonState::PRESSED)
		return true;

	return false;
}

Button::~Button() {
	
}

