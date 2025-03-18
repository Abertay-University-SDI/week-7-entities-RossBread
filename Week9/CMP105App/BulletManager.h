#pragma once
#include "Framework/GameObject.h"
#include "Bullet.h"
#include "Player.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void spawn(sf::Vector2f pos, sf::Vector2f cursorPos);

	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	int bulletRenderCount;

	//sf::Font arial;
	//sf::Text bulletCount;

	sf::Vector2f unitVec;
	float speed = 350.f;

	std::vector<Bullet> projectiles;
	sf::Vector2f spawnPoint;
//	sf::Texture bulletTexture;
};


