#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	player.setInput(input);

	audio.playMusicbyName("monkey");
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);

	if (input->isPressed(sf::Keyboard::Space))
	{
		ball.spawn();
	}
	if (input->isPressed(sf::Keyboard::E)) {
		enemy.spawn();
	}
	if (input->isLeftMousePressed()) {
		bullet.spawn(player.getPosition(), sf::Vector2f(input->getMouseX(), input->getMouseY()));
	}
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	ball.update(dt);
	enemy.update(dt);
	bullet.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	ball.render(window);
	enemy.render(window);
	bullet.render(window);

	window->draw(player);


	endDraw();
}
