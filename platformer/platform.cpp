#include <fstream>
#include <sstream>

#include "platform.h"


Platform::Platform() : Entity()
{
	this->addSprite("assets/test.tga");
	this->sprite()->color = RED;
}

Platform::~Platform()
{

}

void Platform::update(float deltaTime)
{
	this->position -= Point2(1.5, 0);
}

