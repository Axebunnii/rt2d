#include <fstream>
#include <sstream>

#include "platform.h"


Platform::Platform() : Entity()
{
	this->addSprite("assets/platform.tga");

	Line s2;
	s2.addPoint(125, -25);
	s2.addPoint(-125, -25);
	s2.addPoint(-125, 25);
	s2.addPoint(125, 25);
	s2.addPoint(125, -25);
	this->addLine(&s2);

	this->line()->color = BLACK;
}

Platform::~Platform()
{

}

void Platform::update(float deltaTime)
{
	this->position -= Point2(400, 0) * deltaTime;

	rect.x = this->position.x;
	rect.y = this->position.y;
}