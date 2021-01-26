#ifndef ARROW_H
#define ARROW_H

#include <rt2d/scene.h>

/// @brief The MyScene class is the Scene implementation.
class Arrow : public Scene
{
public:
	/// @brief Constructor
	Arrow();
	/// @brief Destructor
	virtual ~Arrow();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void Move(float deltaTime);

private:
	float arrowSpd = 1500;
	float shootSpd = 1000;
	float gravity = 9.81f;
};

#endif /* ARROW_H */
