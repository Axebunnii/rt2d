/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "platform.h"
#include "player.h"
#include "collision.h"
#include "background.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Timer t;

	std::vector<Platform*> platforms;
	Platform* strtpltfrm;
	Platform* strtpltfrm2;
	Background* background;
	Player* player;

	float randomTime = std::rand() % 2;
};

#endif /* SCENE00_H */
