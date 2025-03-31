#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "BeachBallManager.h"
#include "anotherManagerClass.h"
#include "Player.h"
#include "BulletManager.h"
#include <string>
#include <iostream>
#include "Framework/AudioManager.h"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	Player player;

	BulletManager bullet;
	BeachBallManager ball;
	anotherManagerClass enemy;

	AudioManager audio;
};