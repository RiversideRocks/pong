#include "bat.h"

Bat::Bat(float startX, float startY) {
	position.x = startX;
	position.y = startY;
	batShape.setSize(sf::Vector2f(200, 20));
	batShape.setPosition(position);
}

FloatRect Bat::getPosition() {
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape() {
	return batShape;
}

void Bat::moveLeft() {
	if (position.x >= 0) {
		position.x -= batSpeed;
	}
	else {
		position.x = 0;
	}
}

void Bat::moveRight() {
	if (position.x <= 900) {
		position.x += batSpeed;
	}
	else {
		position.x = 900;
	}
}

void Bat::update() {
	batShape.setPosition(position);
}