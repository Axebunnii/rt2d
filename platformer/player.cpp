#include <fstream>
#include <sstream>

#include "player.h"


Player::Player() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = BLUE;
}

Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	//if (no collision)
	this->position += Point(0, 0.5);
}