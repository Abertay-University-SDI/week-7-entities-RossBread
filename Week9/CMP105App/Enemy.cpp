#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	move(velocity * dt);
}
