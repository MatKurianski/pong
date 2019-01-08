#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"

class Player {
	private:
		float movementSpeed;
		sf::Vector2f *vector;
		sf::RectangleShape *shape;
	public:
		Player(float x, float y);
		
		float getSizeX();
		float getSizeY();
		float getPositionX();
		float getPositionY();
		float getMovementSpeed();
		bool shouldMove(Pong::direction direction);
		void move(Pong::direction direction);
		sf::RectangleShape getShapeData();
		sf::Vector2f getFullVector();
};

#endif
