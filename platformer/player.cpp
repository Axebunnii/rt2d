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

	jumpspd = 0;
}

Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	//rect->position = this->position;
	rect.x = this->position.x;
	rect.y = this->position.y;

	AddGravity(deltaTime);
	Jump(deltaTime);
}

void Player::CheckCollision(Platform* p) {

	if (Collision::rectangle2rectangle(rect, p->rect)) {
		isColliding = true;
		this->line()->color = RED;
	}
	else {
		isColliding = false;
	}
	//std::cout << isColliding << std::endl;
}

void Player::AddGravity(float deltaTime) {
	if (!isColliding) {
		this->position.y += gravity - jumpspd;
	}
}

void Player::Jump(float deltaTime) {

	if (input()->getKeyDown(KeyCode::Space)) {
		std::cout << "Jump" << std::endl;
		isJumping = true;
		jumpspd = 10;
	}

	else {
		isJumping = false;
	}

	if (jumpspd > 0) {
		jumpspd -= 0.1f;
	}
}