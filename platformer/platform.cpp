#include <fstream>
#include <sstream>

#include "platform.h"


Platform::Platform() : Entity()
{
	this->addSprite("assets/platform.tga");
}

Platform::~Platform()
{

}

void Platform::update(float deltaTime)
{
	this->position -= Point2(380, 0) * deltaTime;

	rect.x = this->position.x;
	rect.y = this->position.y;
}