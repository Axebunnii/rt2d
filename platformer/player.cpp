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

	this->line()->color = BLACK;
}

Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	//if (no collision)
	//this->position += Point(0, 0.5);

	/*if (rect.x < platform.rect.x + platform.rect.width &&
		rect.x + rect.width > platform.rect.x &&
		rect.y < platform.rect.y + platform.rect.height &&
		rect.y + rect.height > platform.rect.y) {
		std::cout << "colliding" << std::endl;
	}*/

	//rect->position = this->position;
	rect.x = this->position.x;
	rect.y = this->position.y;

	AddGravity();
}

void Player::CheckCollision(Platform* p) {

	if (Collision::rectangle2rectangle(rect, p->rect)) {
		isColliding = true;
		this->line()->color = RED;
	}
	//std::cout << isColliding << std::endl;
}

void Player::AddGravity() {
	this->position.y += 1;
}
