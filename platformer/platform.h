#ifndef PLATFORM_H
#define PLATFORM_H

#include <rt2d/entity.h>
#include "collision.h"

/// @brief The MyEntity class is the Entity implementation.
class Platform : public Entity
{
public:
	/// @brief Constructor
	Platform();
	/// @brief Destructor
	virtual ~Platform();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Rectangle rect = Rectangle(this->position.x, this->position.y, 250, 50);


private:
	/* add your private declarations */

	bool isdeleted = false;

};

#endif /* PLATFORM_H */