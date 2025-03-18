#pragma once
#include "Framework/GameObject.h"
#include "anotherManagerClass.h"
#include <iostream>

anotherManagerClass::anotherManagerClass()
{
	enemyRenderCount = 0;

	EnemyTexture.loadFromFile("gfx/Goomba.png");

	for (int i = 0; i < 40; i++) {
		enemies.push_back(Enemy());
		enemies[i].setAlive(false);
		enemies[i].setTexture(&EnemyTexture);
		enemies[i].setSize(sf::Vector2f(50, 50));
	}

	arial.loadFromFile("font/arial.ttf");
	enemyCount.setFont(arial);
	enemyCount.setPosition(sf::Vector2f(0, 0));
	enemyCount.setFillColor(sf::Color::Black);
}

anotherManagerClass::~anotherManagerClass()
{
}

void anotherManagerClass::spawn()
{
	for (int i = 0; i < enemies.size(); i++) {
		if (!enemies[i].isAlive()) {
			enemies[i].setAlive(true);
			enemies[i].setVelocity(0,80.f);
			enemies[i].setPosition(rand() % 1150, -50);
			enemyRenderCount++;
			return;
		}
	}
}

void anotherManagerClass::update(float dt)
{
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].isAlive()) {
			enemies[i].update(dt);
		}
	}
	deathCheck();

	enemyCount.setString("Enemies Rendered: " + std::to_string(enemyRenderCount));
}

void anotherManagerClass::deathCheck()
{
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].isAlive()) {
			if (enemies[i].getPosition().y > 650) {
				enemies[i].setAlive(false);
				enemyRenderCount--;
			}
		}
	}
}

void anotherManagerClass::render(sf::RenderWindow* window)
{
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].isAlive()) {
			window->draw(enemies[i]);
		}
	}
	window->draw(enemyCount);
}
