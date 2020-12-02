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
	/*if (isdeleted) {
		std::cout << "Deleting platform" << std::endl;
		this->removeChild(this);
		delete this;
	}*/
}

void Platform::update(float deltaTime)
{
	this->position -= Point2(0.7, 0);
	/*if (this->position.x <= 1000 && !isdeleted) {
		isdeleted = true;
		std::cout << "isdeleted = true" << std::endl;
	}*/
}

