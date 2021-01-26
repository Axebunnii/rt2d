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
	et.start();

	background = new Background();
	background->position = Point2(SWIDTH/2, SHEIGHT/2);

	this->addChild(background);

	strtpltfrm = new Platform();
	strtpltfrm->position = Point2(SWIDTH / 2 + SWIDTH / 8, SHEIGHT / 2);
	//strtpltfrm->scale = Point(4, 1);
	this->addChild(strtpltfrm);
	platforms.push_back(strtpltfrm);

	strtpltfrm2 = new Platform();
	strtpltfrm2->position = Point2(SWIDTH / 2 + SWIDTH / 2, SHEIGHT / 2);
	this->addChild(strtpltfrm2);
	platforms.push_back(strtpltfrm2);

	//player
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/2 - SHEIGHT/4);

	this->addChild(player);
}


MyScene::~MyScene()
{
	this->removeChild(background);
	delete background;

	this->removeChild(player);
	delete player;
	
	for (int i = 0; i < platforms.size(); i++) {
		this->removeChild(platforms[i]);
		delete platforms[i];
	}

	for (int i = 0; i < arrows.size(); i++) {
		this->removeChild(arrows[i]);
		delete arrows[i];
	}

	for (int i = 0; i < enemies.size(); i++) {
		this->removeChild(enemies[i]);
		delete enemies[i];
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

	//player->CheckCollision(strtpltfrm);

	if (t.seconds() > randomTime) {
		t.start();

		Platform* platform = new Platform();
		platform->position = Point2(SWIDTH + 100, std::rand() % SHEIGHT/3 + SHEIGHT / 4);
		
		this->addChild(platform);
		platforms.push_back(platform);
	}

	/*for (int i = 0; i < platforms.size(); i++) {
		player->CheckCollision(platforms[i]);
	}*/
	player->CheckCollision(platforms);

	SpawnArrow();
	SpawnEnemy();
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->MoveEnemy(deltaTime, player->position);
	}
}

void MyScene::SpawnArrow() {
	if (input()->getKeyUp(KeyCode::E)) {
		std::cout << "Shooting arrow" << std::endl;
		Arrow* a = new Arrow();
		a->position = Point2(player->position.x, player->position.y + 75);
		a->rotation.z = 25;

		this->addChild(a);
		arrows.push_back(a);
	}
}

void MyScene::SpawnEnemy() {
	std::cout << "Spawn Enemy" << std::endl;
	if (et.seconds() > 5) {
		std::cout << et.seconds() << std::endl;
		et.start();
		
		Enemy* e = new Enemy();
		
		this->addChild(e);
		enemies.push_back(e);
	}
	player->CheckEnemyHit(enemies);
}