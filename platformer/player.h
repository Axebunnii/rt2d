#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include <math.h>
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

	void AddGravity();

	void CheckCollision(Platform* p);

	void Jump();

private:
	/* add your private declarations */
	Rectangle rect = Rectangle(this->position.x - 75, this->position.y - 100, 150, 200);
	bool isColliding = false;
	bool isJumping = false;
	Vector2 jumpPos;		//jump start position
	Vector2 jumpLimit;		//jump height limit
	Vector2 acc;			//acceleration
	Vector2 vel;			//velocity
	Vector2 maxvel;			//maximal velocity
	float mass = 1;
	float gravity = 0.981f;
};

#endif /* PLAYER_H */