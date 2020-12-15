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

	background = new Background();
	background->position = Point2(SWIDTH/2, SHEIGHT/2);

	this->addChild(background);

	strtpltfrm = new Platform();
	strtpltfrm->position = Point2(SWIDTH / 2 + SWIDTH / 8, SHEIGHT / 2);
	strtpltfrm->scale = Point(4, 1);
	this->addChild(strtpltfrm);

	//player
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/2 - SHEIGHT/4);

	this->addChild(player);
}


MyScene::~MyScene()
{
	this->removeChild(background);
	delete background;

	this->removeChild(strtpltfrm);
	delete strtpltfrm;

	this->removeChild(player);
	delete player;
	
	for (int i = 0; i < platforms.size(); i++) {
		this->removeChild(platforms[i]);
		delete platforms[i];
	}
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	player->CheckCollision(strtpltfrm);

	if (t.seconds() > randomTime) {
		t.start();

		Platform* platform = new Platform();
		platform->position = Point2(SWIDTH + 100, std::rand() % SHEIGHT/3 + SHEIGHT / 4);
		
		this->addChild(platform);
		platforms.push_back(platform);
	}

	for (int i = 0; i < platforms.size(); i++) {
		player->CheckCollision(platforms[i]);
	}
}