#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"
#include "CONSTANTS.h"

int main() {
	Player player(15.f, 170.f);
	sf::RenderWindow window(sf::VideoMode(Pong::SCREEN_WIDTH, Pong::SCREEN_HEIGHT), "Pong");
	
	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		window.clear(sf::Color::Black);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			player.move(Pong::UP);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			player.move(Pong::DOWN);

		window.draw(player.getShapeData());
		window.display();
	}
	return 0;
}
