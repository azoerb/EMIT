/*
 *  Controller.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Door 6. All rights reserved.
 *
 */

#pragma once

#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <chipmunk.h>

#define vec2 sf::Vector2f

class GameObject;
class LevelObject;

class Controller {
private:
    sf::RenderWindow* window;
    
    sf::Image* birdImg;
    sf::Image* mapImg;
    
    GameObject* bird;
    LevelObject* map;
    
    float elapsedTime;
    
    cpShape* ballShape;
    cpBody* ballBody;
    cpSpace* space;
    cpShape *ground;
    
public:
    Controller();
    ~Controller();
    
    void mainLoop();
    void update();
    void checkCollision(GameObject*);
    bool checkLineCollision(vec2 start1, vec2 end1, vec2 start2, vec2 end2);
    void draw();
    void processEvents();
    void loadResources();
    void initializeObjects();
};