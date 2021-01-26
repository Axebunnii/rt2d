#include <fstream>
#include <sstream>

#include "arrow.h"

Arrow::Arrow() : Scene()
{
	this->addSprite("assets/arrow.tga");
}

Arrow::~Arrow()
{
	
}

void Arrow::update(float deltaTime)
{
	Move(deltaTime);
}

void Arrow::Move(float deltaTime) {
	if (arrowSpd != 0) {
		arrowSpd -= 1.5;
	}
	this->position.x += arrowSpd * deltaTime;

	shootSpd -= 10;
	this->position.y -= shootSpd * deltaTime;
	this->position.y += gravity * deltaTime;

	this->rotation.z += 0.002;
}