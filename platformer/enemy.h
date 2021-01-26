#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include "collision.h"

/// @brief The MyScene class is the Scene implementation.
class Enemy : public Entity
{
public:
	/// @brief Constructor
	Enemy();
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void MoveEnemy(float deltaTime, Point2 playerPos);

	Rectangle rect = Rectangle(this->position.x, this->position.y, 150, 150);

private:
	Point2 distance;
	float spd = 0.5;
};

#endif /* ENEMY_H */