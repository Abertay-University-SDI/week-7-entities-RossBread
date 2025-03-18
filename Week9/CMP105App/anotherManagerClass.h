#pragma once
#include "Framework/GameObject.h"
#include "Enemy.h"

class anotherManagerClass
{
public:
	anotherManagerClass();
	~anotherManagerClass();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	int enemyRenderCount;

	sf::Font arial;
	sf::Text enemyCount;

	std::vector<Enemy> enemies;
	sf::Vector2f spawnPoint;
	sf::Texture EnemyTexture;
};

