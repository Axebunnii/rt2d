/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	std::srand(std::time(nullptr));

	// start the timer.
	t.start();
	pt.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(std::rand()%SWIDTH, std::rand()%SHEIGHT);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);

	platform = new Platform();
	platform->position = Point2(SWIDTH, std::rand() % SHEIGHT);

	this->addChild(platform);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;

	this->removeChild(platform);
	delete platform;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.10f);
		t.start();
	}

	/*int randomNum = std::rand() % 200;
	if (randomNum >= 199) {
		platform = new Platform();
		platform->position = Point2(SWIDTH, std::rand() % SHEIGHT);

		this->addChild(platform);
	}*/

	float time = 0.7;
	std::cout << "Time: " << time << std::endl;
	std::cout << "seconds: " << pt.seconds() << std::endl;
	if (pt.seconds() > time) {
		pt.start();

		platform = new Platform();
		platform->position = Point2(SWIDTH + 100, std::rand() % SHEIGHT + SHEIGHT/4);

		this->addChild(platform);
	}	
}