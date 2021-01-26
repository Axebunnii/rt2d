#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include "collision.h"
#include "platform.h"
#include "arrow.h"
#include "enemy.h"

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

	void AddGravity(float deltaTime);

	void CheckCollision(std::vector<Platform*>& platformlist);

	void Jump(float deltaTime);
	//Arrow* Shoot();
	void CheckEnemyHit(std::vector<Enemy*>& enemylist);


private:
	/* add your private declarations */
	Rectangle rect = Rectangle(this->position.x, this->position.y, 150, 130);
	bool isColliding = false;
	bool isJumping = false;
	float jumpspd;
	float gravity = 400;
};

#endif /* PLAYER_H */