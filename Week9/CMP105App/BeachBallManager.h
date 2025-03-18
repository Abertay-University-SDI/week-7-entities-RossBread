#pragma once
#include "Framework/GameObject.h"
#include "Ball.h"

class BeachBallManager
{
public:
	BeachBallManager();
	~BeachBallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
};

