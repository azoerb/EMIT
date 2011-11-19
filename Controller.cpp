/*
 *  Controller.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Door 6. All rights reserved.
 *
 */

#include "Controller.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/LevelObject.h"
#include <math.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

#define JUMP_HEIGHT 4.0
#define FALL_SPEED 9800.0

#define MAX_CLIMABLE_SLOPE  1

Controller::Controller() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "EMIT");
    
    birdImg = new sf::Image();
    mapImg = new sf::Image();
    
    loadResources();
    initializeObjects();
}

Controller::~Controller() {
    if (window) { delete window; }
    if (birdImg) { delete birdImg; }
    if (bird) { delete bird; }
    if (mapImg) { delete mapImg; }
    if (map) { delete map; }
}

void Controller::mainLoop() {
    while (window->IsOpened()) {
        update();
        draw();
    }
}

void Controller::update() {
    processEvents();
    
    elapsedTime = window->GetFrameTime();
    
    // Move the sprite
    if (window->GetInput().IsKeyDown(sf::Key::Left)) {
        if (map->getPosition().x < 0) {
            map->setPosition(map->getPosition() + vec2(100 * elapsedTime, 0));
        }
    }
    if (window->GetInput().IsKeyDown(sf::Key::Right)) {
        if (map->getPosition().x > -3200 + WINDOW_WIDTH) {
            map->setPosition(map->getPosition() + vec2(-100 * elapsedTime, 0));
        }
    }
    
    if (bird->getPosition().y < WINDOW_HEIGHT - 100) {
        bird->changeVelocity(sf::Vector2f(0, FALL_SPEED * elapsedTime * elapsedTime));
    } else {
        bird->setVelocity(sf::Vector2f(0, 0));
        if (window->GetInput().IsKeyDown(sf::Key::Up)) {
            bird->changeVelocity(sf::Vector2f(0, -JUMP_HEIGHT));
        }
    }
    
    bird->changePosition(bird->getVelocity());
    checkCollision(bird);
}

void Controller::checkCollision(GameObject* go) {
    std::vector<vec2> points = go->getPoints();
    std::vector<vec2> mapPoints = map->getPoints();
    
    // Translate collision points to player position
    for (int i = 0; i < points.size(); i++) {
        points[i] += go->getPosition();
    }
    for (int j = 0; j < mapPoints.size(); j++) {
        mapPoints[j] += map->getPosition();
    }
    
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < mapPoints.size() - 1; j++) {
            while (checkLineCollision(points[i], points[i + 1], mapPoints[j], mapPoints[j + 1])) {
                float slope;
                if (mapPoints[j + 1].x != mapPoints[j].x) {
                    slope = (mapPoints[j + 1].y - mapPoints[j].y) / (mapPoints[j + 1].x - mapPoints[j].x);
                } else {
                    slope = MAX_CLIMABLE_SLOPE + 1;
                }
                printf("%f\n", slope);
                if (fabs(slope) <= MAX_CLIMABLE_SLOPE) {
                    go->changePosition(vec2(0.0, -0.5));
                    for (int i = 0; i < points.size(); i++) {
                        points[i] += vec2(0.0, -0.5);
                    }
                } else {
                    go->changePosition(vec2(-0.5, 0.0));
                    for (int i = 0; i < points.size(); i++) {
                        points[i] += vec2(-0.5, 0.0);
                    }
                }
            }
        }
    }
}

// Collision detection algorithm.  Checks whether two lines are overlapping.
bool Controller::checkLineCollision(vec2 start1, vec2 end1, vec2 start2, vec2 end2) { 
	vec2 line1 = vec2(end1.x - start1.x, end1.y - start1.y);
	vec2 line2 = vec2(end2.x - start2.x, end2.y - start2.y);
    
	float b_dot_d_perp = line1.x * line2.y - line1.y * line2.x;
	if(b_dot_d_perp == 0) {
		return false;
	}
    
	float cx = start2.x - start1.x;
	float cy = start2.y - start1.y;
    
	float t = (cx * line2.y - cy * line2.x) / b_dot_d_perp;
	if(t < 0 || t > 1) {
		return false;
	}
    
	float u = (cx * line1.y - cy * line1.x) / b_dot_d_perp;
	if(u < 0 || u > 1) { 
		return false;
	}
    
	return true;
}

void Controller::draw() {
    window->Clear();
    
    window->Draw(*map->getSprite());
    window->Draw(*bird->getSprite());
    
    window->Display();
}

void Controller::processEvents() {
    // Process events
    sf::Event Event;
    while (window->GetEvent(Event)) {
        // Close window : exit
        if (Event.Type == sf::Event::Closed)
            window->Close();
    }
}

void Controller::loadResources() {
    if (!birdImg->LoadFromFile("../Resources/Bird.png")) {
        window->Close();
    }
    if (!mapImg->LoadFromFile("../Resources/Map.png")) {
        window->Close();
    }
}

void Controller::initializeObjects() {
    bird = new GameObject(birdImg);
    bird->setPosition(vec2(0, 400));
    std::vector<vec2> birdPoints;
    vec2 dim = bird->getDimensions();
    birdPoints.push_back(vec2(0.0, 0.0));
    birdPoints.push_back(vec2(0.0, dim.y));
    birdPoints.push_back(vec2(dim.x, dim.y));
    birdPoints.push_back(vec2(dim.x, 0.0));
    bird->setPoints(birdPoints);
    
    
    map = new LevelObject(mapImg);
    std::vector<vec2> mapPoints;
    mapPoints.push_back(vec2(20, WINDOW_HEIGHT));
    mapPoints.push_back(vec2(50, 0));
    map->setPoints(mapPoints);
}