#include "Player.h"
#include <iostream>

Player::Player()
{
	playerTexture.loadFromFile("gfx/MushroomTrans.png");

	setTexture(&playerTexture);
	setPosition(100, 100);
	setSize(sf::Vector2f(50, 50));

}

Player::~Player()
{
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::A)) {
		setVelocity(-200.f,0);
		move(velocity * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S)) {
		setVelocity(0, 200.f);
		move(velocity * dt);
	}
	if (input->isKeyDown(sf::Keyboard::W)) {
		setVelocity(0, -200.f);
		move(velocity * dt);
	}
	if (input->isKeyDown(sf::Keyboard::D)) {
		setVelocity(200.f, 0);
		move(velocity * dt);
	}

	//std::cout << "pos x: " << getPosition().x << " y: " << getPosition().y << "\n" ;
}

void Player::update(float dt)
{
}
