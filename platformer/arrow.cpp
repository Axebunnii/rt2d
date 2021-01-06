#include <fstream>
#include <sstream>

#include "arrow.h"

Arrow::Arrow() : Scene()
{
	this->addSprite("assets/platform.tga");
}

Arrow::~Arrow()
{
	
}

void Arrow::update(float deltaTime)
{
	this->position.x += arrowSpd * deltaTime;

	//give the arrow gravity
	this->position.y += gravity * deltaTime;
}