#include <fstream>
#include <sstream>

#include "player.h"


Player::Player() : Entity()
{
	Line s1;
	s1.addPoint(0, 0);
	s1.addPoint(75, 0);
	s1.addPoint(75, 100);
	s1.addPoint(0, 100);
	s1.addPoint(0, 0);
	this->addLine(&s1);

	this->line()->color = BLUE;
	
}

Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	//if (no collision)
	//this->position += Point(0, 0.5);
	CheckCollider();
}