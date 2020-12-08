#ifndef VECTOR_H
#define VECTOR_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Vector : public Entity
{
public:
	/// @brief Constructor
	Vector();
	/// @brief Destructor
	virtual ~Vector();

	static bool Vector2(float x, float y) {

	}

	static bool AddGravity() {

	}

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */


};

#endif /* VECTOR_H */