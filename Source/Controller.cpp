/*
 *  Controller.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "Controller.h"
#include "GameObjects/GameObject.h"
#include "Renderer.h"
#include "ResourceHandler.h"
#include "InputHandler.h"
#include <math.h>
#include <stdio.h>

Controller::Controller() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "EMIT");
    window->UseVerticalSync(true);
    
    renderer = new Renderer(window);
    resourceHandler = new ResourceHandler();
    inputHandler = new InputHandler(window);
    
    resourceHandler->loadResources();
    
    initializeObjects();
}

Controller::~Controller() {
    if (debugDraw) { delete debugDraw; }
    if (window) { delete window; }
    if (renderer) { delete renderer; }
    if (resourceHandler) { delete resourceHandler; }
}

void Controller::mainLoop() {
    while (window->IsOpened()) {
        update();
        drawScene();
    }
}

void Controller::update() {
    elapsedTime = window->GetFrameTime();
    
    inputHandler->update();
    
    world->Step(TIME_STEP / 5, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
                
    // Update objects
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects.at(i)->update(elapsedTime);
    }    
}

void Controller::drawScene() {
    window->Clear();
    
    // Draw all of the game objects
    for (int i = 0; i < gameObjects.size(); i++) {
        renderer->render(gameObjects.at(i));
    }
    world->DrawDebugData();
    window->Display();
}

void Controller::initializeObjects() {
	b2Vec2 gravity(0.0f, 9.8f);    
	world = new b2World(gravity);
    
    debugDraw = new DebugDraw(*window);
    world->SetDebugDraw(debugDraw);
    
    GameObject* floor = new GameObject();
    b2Vec2 verts[3];
    verts[0].Set(0.0, 0.0);
    verts[2].Set(10.0, 10.0);
    verts[1].Set(20.0, 10.0);
    addComponent(floor, new PhysicsComponent(world, 100.0, 0.0, verts, 3, 0.0, .6), COMP_TYPE_PHYSICS);
    gameObjects.push_back(floor);
    
    
    GameObject* obj = new GameObject();
    sf::Image* img = resourceHandler->getImage("bird");
    addComponent(obj, new InputComponent(), COMP_TYPE_INPUT);
    addComponent(obj, new RenderableComponent(img), COMP_TYPE_RENDERABLE);
    addComponent(obj, new PhysicsComponent(world, 250.0, 0.0, .25, .25, 1.0, .6), COMP_TYPE_PHYSICS);
    PhysicsComponent* comp1 = (PhysicsComponent*) obj->getComponent(COMP_TYPE_PHYSICS);
    RenderableComponent* comp2 = (RenderableComponent*) obj->getComponent(COMP_TYPE_RENDERABLE);
    comp2->update(0.0, comp1->getPosition(), 0.0);
    gameObjects.push_back(obj);

}

void Controller::addComponent(GameObject* obj, Component* comp, ComponentType type) {
    switch (type) {
        case COMP_TYPE_INPUT:
            ((InputComponent*) comp)->registerHandler(inputHandler);
            break;
    }
    obj->addComponent(comp, type);
}