#ifndef PLATFORM_H
#define PLATFORM_H

/// @brief The MyEntity class is the Entity implementation.
class Platform : public Platform
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

private:
	/* add your private declarations */


};

#endif /* PLATFORM_H */