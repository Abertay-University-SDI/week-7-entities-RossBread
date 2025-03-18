#include "BulletManager.h"
#include <iostream>
#include <cmath>

BulletManager::BulletManager()
{
	bulletRenderCount = 0;

	//for (int i = 0; i < 20; i++) {
	//	projectiles.push_back(Bullet());
	//	projectiles[i].setSize(sf::Vector2f(4,4));
	//	projectiles[i].setFillColor(sf::Color::White);
	//	projectiles[i].setAlive(false);
	//	return;
	//}
	
}

BulletManager::~BulletManager()
{
}

void BulletManager::spawn(sf::Vector2f pos, sf::Vector2f cursorPos) // there is almost definitely a way to do this without param passing but i cant remember
{
	sf::Vector2f dirVec = cursorPos - pos;
	float magVec = hypot(dirVec.x, dirVec.y);

	sf::Vector2f unitVec;
		unitVec = dirVec / magVec;
	

	std::cout << "magVec: " << magVec << "\n";
	std::cout << "dirVec x: " << dirVec.x << " y: " << dirVec.y << "\n";
	std::cout << "unitVec x: " << unitVec.x << " y: " << unitVec.y << "\n\n";

	for (int i = 0; i < projectiles.size(); i++) {
		if (!projectiles[i].isAlive()) {
			projectiles[i].setAlive(true);
			projectiles[i].setVelocity(unitVec * speed);
			projectiles[i].setPosition(pos + sf::Vector2f(25,25));
			///bulletRenderCount++;

			return;
		}
	}

	// no avaliable space in the vector (same as BeachBallManager)

	projectiles.push_back(Bullet());
	projectiles[projectiles.size() - 1].setAlive(true);
	projectiles[projectiles.size() - 1].setVelocity(unitVec * speed);
	projectiles[projectiles.size() - 1].setPosition(pos + sf::Vector2f(25, 25));
	projectiles[projectiles.size() - 1].setSize(sf::Vector2f(4, 4));
	projectiles[projectiles.size() - 1].setFillColor(sf::Color::White);

}

void BulletManager::update(float dt)
{
	for (int i = 0; i < projectiles.size(); i++) {
		if (projectiles[i].isAlive()) {
			projectiles[i].update(dt);
		}
	}
	deathCheck();
}

void BulletManager::deathCheck() {
	for (int i = 0; i < projectiles.size(); i++) {
		if (projectiles[i].isAlive()) {
			if (projectiles[i].getPosition().x < -100) {
				projectiles[i].setAlive(false);
			}
			if (projectiles[i].getPosition().x > 800) {
				projectiles[i].setAlive(false);
			}
			if (projectiles[i].getPosition().y < -100) {
				projectiles[i].setAlive(false);
			}
			if (projectiles[i].getPosition().y > 600) {
				projectiles[i].setAlive(false);
			}
		}
	}
}

void BulletManager::render(sf::RenderWindow* window) {
	for (int i = 0; i < projectiles.size(); i++) {
		if (projectiles[i].isAlive()) {
			window->draw(projectiles[i]);
		}
	}
}
