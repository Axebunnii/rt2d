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
	if (arrowSpd != 0) {
		arrowSpd -= 2;
	}

	this->position.x += arrowSpd * deltaTime;

	
	shootSpd -= 4;

	this->position.y -= shootSpd * deltaTime;
	this->position.y += gravity * deltaTime;

	this->rotation.z += 0.001;
}