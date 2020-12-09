#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include "collision.h"
#include "platform.h"

/// @brief The MyEntity class is the Entity implementation.
class Player : public Entity
{
public:
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void CheckCollision(Platform* p);


private:
	/* add your private declarations */
	bool isColliding = false;
	Rectangle rect = Rectangle(this->position.x, this->position.y, 150, 200);
};

#endif /* PLAYER_H */