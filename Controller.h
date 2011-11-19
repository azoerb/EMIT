/*
 *  Controller.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Door 6. All rights reserved.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>

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