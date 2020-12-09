#include <fstream>
#include <sstream>

#include "background.h"


Background::Background() : Entity()
{
	this->addSprite("assets/background.tga");
}

Background::~Background()
{

}

void Background::update(float deltaTime)
{
	
}