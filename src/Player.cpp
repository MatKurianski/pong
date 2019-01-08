#include <SFML/Graphics.hpp>
#include "Player.h"
#include "CONSTANTS.h"

Player::Player(float x, float y) {
	movementSpeed = 0.35f;
	vector = new sf::Vector2f(x, y);
	shape = new sf::RectangleShape(this->getFullVector());

	shape->setFillColor(sf::Color::White);
	shape->setOrigin(this->getSizeX()/2, this->getSizeY()/2);
	shape->setPosition(50.f, Pong::SCREEN_HEIGHT / 2);
}

float Player::getSizeX() {
	return vector->x;
}

float Player::getSizeY() {
	return vector->y;
}

float Player::getPositionX() {
	return shape->getPosition().x;
}

float Player::getPositionY() {
	return shape->getPosition().y;
}

float Player::getMovementSpeed() {
	return movementSpeed;
}

bool Player::shouldMove(Pong::direction direction) {
	switch(direction) {
		case Pong::UP:
			if(this->getPositionY() - (this->getSizeY() / 2) - this->getMovementSpeed() > 0)
				return true;
			break;
		case Pong::DOWN:
			if(this->getPositionY() + (this->getSizeY() / 2) + this->getMovementSpeed() < Pong::SCREEN_HEIGHT)
				return true;
			break;
	}
	return false;
}

void Player::move(Pong::direction direction) {
	if(!shouldMove(direction)) return;
	switch (direction) {
		case Pong::UP:
			shape->move(sf::Vector2f(0.0f, -movementSpeed));
			break;
		case Pong::DOWN:
			shape->move(sf::Vector2f(0.0f, movementSpeed));
			break;
	}
}

sf::Vector2f Player::getFullVector() {
	return *vector;
}

sf::RectangleShape Player::getShapeData() {
	return *shape;
}
