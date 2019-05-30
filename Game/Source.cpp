#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Dungeon Run");

	while (renderWindow.isOpen())
	{
		sf::Event event;

		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}

			renderWindow.clear(sf::Color::White);
			renderWindow.display();
		}
	}
}