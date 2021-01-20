#include <fstream>
#include <sstream>

#include "enemy.h"

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/enemy.tga");
	this->position = Point2(SWIDTH + SWIDTH/2, 0);
}

Enemy::~Enemy()
{
	
}

void Enemy::update(float deltaTime)
{
	
}

void Enemy::MoveEnemy(float deltaTime, Point2 playerpos)
{
	distance = this->position - playerpos;
	this->position -= (distance * spd) * deltaTime;
}