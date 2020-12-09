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
	
	//player
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/2);

	this->addChild(player);
}


MyScene::~MyScene()
{
	this->removeChild(player);
	delete player;
	
	/*for (int i = 0; i <= platforms.size(); i++) {
		this->removeChild(platforms[i]);
		delete platforms[i];
	}*/
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	//std::cout << "Time: " << randomTime << std::endl;
	//std::cout << "seconds: " << pt.seconds() << std::endl;
	if (pt.seconds() > randomTime) {
		pt.start();

		Platform* platform = new Platform();
		platform->position = Point2(SWIDTH + 100, std::rand() % SHEIGHT/3 + SHEIGHT / 4);
		
		this->addChild(platform);
		platforms.push_back(platform);
	}

	for (int i = 0; i < platforms.size(); i++) {
		player->CheckCollision(platforms[i]);
	}
}