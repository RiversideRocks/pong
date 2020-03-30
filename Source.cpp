#include "bat.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>

using namespace sf;

int main() {
	int windowWidth = 1024;
	int windowHeight = 768;
	// Declare and load a font
	Font font;
	font.loadFromFile("Halt.ttf");

	// Declare a new sound buffer
	SoundBuffer buffer;
	if (!buffer.loadFromFile("Ali (1).wav"))
	{
		std::cerr << "Cannot locate sound file" << std::endl;
	}
	// Create a sound source and bind it to the buffer
	Sound sound1;
	sound1.setBuffer(buffer);
	// Play the sound
	//sound1.play();


	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
	
	Bat bat(windowWidth / 2, windowHeight - 20);
	Ball ball(windowWidth / 2, 1);
	
		while (window.isOpen()) {

			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {
					window.close();
				}
			}
			//TEXT STUFF
			Text text("Pong Game", font);
			text.setCharacterSize(150);
			text.setStyle(sf::Text::Bold);
			text.setFillColor(sf::Color::Cyan);

			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				bat.moveLeft();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Right)) {
				bat.moveRight();
			}

			if (ball.getPosition().top < 0) {
				ball.reboundBatOrTop();
			}

			if (ball.getPosition().top > windowHeight) {
				ball.hitBottom();
			}

			if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth) {
				ball.reboundSides();
			}

			if (ball.getPosition().intersects(bat.getPosition())) {
				sound1.play();
				ball.reboundBatOrTop();
			}
			
			bat.update();
			ball.update();

			window.clear(Color(148, 213, 0, 255));
			window.draw(bat.getShape());
			window.draw(ball.getShape());
			window.draw(text);
			window.display();
		}
}