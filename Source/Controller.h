/*
 *  Controller.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Constants.h"
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "Box2D.h"

class Renderer;
class ResourceHandler;
class InputHandler;
class GameObject;

class Controller {
private:
    sf::RenderWindow* window;
    
    Renderer* renderer;
    ResourceHandler* resourceHandler;
    InputHandler* inputHandler;
    
    std::vector<GameObject*> gameObjects;
    
    b2World* world;
    b2Body* groundBody;
    b2Body* body;
    
    float elapsedTime;
    
public:
    Controller();
    ~Controller();
    
    void mainLoop();
    void update();
    void drawScene();
    void loadResources();
    void initializeObjects();
    void addComponent(GameObject* obj, Component* comp, ComponentType type);
};