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

	Line s1;
	s1.addPoint(0, 0);
	s1.addPoint(75, 0);
	s1.addPoint(75, 100);
	s1.addPoint(0, 100);
	s1.addPoint(0, 0);
	player->addLine(&s1);

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

		platform = new Platform();
		platform->position = Point2(SWIDTH + 100, std::rand() % SHEIGHT/3 + SHEIGHT / 4);

		Line s2;
		s2.addPoint(125, -25);
		s2.addPoint(-125, -25);
		s2.addPoint(-125, 25);
		s2.addPoint(125, 25);
		s2.addPoint(125, -25);
		platform->addLine(&s2);
	
		platform->line()->color = BLACK;
		//platform rect
		Rectangle rect2 = Rectangle(platform->position.x, platform->position.y, 1, 1);
		
		this->addChild(platform);
		platforms.push_back(platform);

	}
	//player rect
	Rectangle rect1 = Rectangle(player->position.x, player->position.y, 1, 1);
	player->line()->color = BLUE;

	/*if (Collision::rectangle2rectangle(rect1, rect2)) {
		std::cout << "colliding" << std::endl;
		player->line()->color = RED;
		platform->line()->color = RED;
	}*/
}