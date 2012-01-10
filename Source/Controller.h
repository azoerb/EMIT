/*
 *  Controller.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *  http://www.kobold2d.com/display/KKDOC/Box2D+API+Reference
 */

#pragma once

#include "Constants.h"
#include "Component.h"
#include "DebugDraw.h"
#include <SFML/Graphics.hpp>
#include "Box2D.h"

class Renderer;
class ResourceHandler;
class InputHandler;
class GameObject;

class Controller {
private:
    sf::RenderWindow* window;
    DebugDraw* debugDraw;
    
    Renderer* renderer;
    ResourceHandler* resourceHandler;
    InputHandler* inputHandler;
    
    std::vector<GameObject*> gameObjects;
    
    b2World* world;
    b2Body* groundBody;
    
    float elapsedTime;
    
public:
    Controller();
    ~Controller();
    
    void mainLoop();
    void update();
    void drawScene();
    void loadResources();
    void initializeObjects();
};