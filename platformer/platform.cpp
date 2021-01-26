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
	this->position.x -= 380 * deltaTime;

	rect.x = this->position.x;
	rect.y = this->position.y;
}