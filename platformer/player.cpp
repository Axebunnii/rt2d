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
	Jump();
}

void Player::CheckCollision(Platform* p) {

	if (Collision::rectangle2rectangle(rect, p->rect)) {
		isColliding = true;
		this->line()->color = RED;
	}
	else {
		isColliding = false;
	}
	std::cout << isColliding << std::endl;
}

void Player::AddGravity() {
	if (!isColliding) {
		this->position.y += gravity - jumpspd;
	}
}

void Player::Jump() {

	if (input()->getKeyDown(KeyCode::Space)) {
		std::cout << "Jump" << std::endl;
		isJumping = true;
		jumpspd = 10;
		/*if (!isJumping) {
			jumpspd = 5;
			isJumping = true;
		}*/
		/*if (isColliding && !isJumping) {
			isColliding = false;
			isJumping = true;
			jumpPos.y = this->position.y;
			jumpLimit.y = jumpPos.y - 10;
			std::cout << "is jumping: " << isJumping << std::endl;
			std::cout << "is colliding: " << isColliding << std::endl;
		}*/
	}
	else {
		isJumping = false;
	}

	if (jumpspd > 0) {
		jumpspd -= 0.1f;
	}

	/*vel.y = 0.001f;
	if (input()->getKey(KeyCode::Space)) {
		std::cout << "Jump" << std::endl;

		pos = this->position;

		vel.y *= 1.5;
		//acc = 

		//std::cout << this->position << std::endl;
		/*pos = this->position;
		vel.y += 5;
		acc.y += 0;

		vel.y += acc.y;
		pos.y += vel.y;

		acc.y *= 0;*/
		
		//vel.y = -sqrtf(2.0f * 981.0f * jumpheight);
		//pos.y -= vel.y;

		//this->position.y -= pos.y;
}