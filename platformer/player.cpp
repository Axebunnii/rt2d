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
	Shoot();
}

void Player::CheckCollision(std::vector<Platform*>& platformlist) {
	isColliding = false;
	this->line()->color = BLACK;
	for (int i = 0; i < platformlist.size(); i++) {
		if (Collision::rectangle2rectangle(rect, platformlist[i]->rect)) {
			isColliding = true;
			this->line()->color = RED;
			break;
		}
	}
}

void Player::AddGravity(float deltaTime) {
	if (!isColliding) {
		//this->position.y += gravity - jumpspd * deltaTime;
		this->position.y += gravity * deltaTime;
	}
}

void Player::Jump(float deltaTime) {
	if (input()->getKeyDown(KeyCode::Space)) {
		if (isColliding) {
			std::cout << "Jump" << std::endl;
			isJumping = true;
			jumpspd = 1000;
		}
	}
	else {
		isJumping = false;
	}

	if (jumpspd > 0) {
		jumpspd -= 1000 * deltaTime;
	}
	this->position.y -= jumpspd * deltaTime;
}

Arrow* Player::Shoot() {
	Arrow* a = new Arrow();
	return a;
}

void Player::CheckEnemyHit(std::vector<Enemy*>& enemylist) {
	std::cout << "Check enemy hit" << std::endl;
	for (int i = 0; i < enemylist.size(); i++) {
		std::cout << "Check enemy hit: for" << std::endl;
		if (Collision::rectangle2rectangle(rect, enemylist[i]->rect)) {
			std::cout << "enemy hit player" << std::endl;
			break;
		}
	}
}