#pragma once
#include "FrameWork/GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void handleInput(float dt);
	void update(float dt);

private:
	sf::Texture playerTexture;
};

