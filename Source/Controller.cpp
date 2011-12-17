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
#include <math.h>
#include <stdio.h>

Controller::Controller() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "EMIT");
    window->UseVerticalSync(true);
    
    renderer = new Renderer(window);
    resourceHandler = new ResourceHandler();
    
    resourceHandler->loadResources();
    initializeObjects();
}

Controller::~Controller() {
    if (window) { delete window; }
    if (renderer) { delete renderer; }
    if (resourceHandler) { delete resourceHandler; }
    
    
    // Clean up our objects and exit!
    cpShapeFree(ground);
    cpSpaceFree(space);
}

void Controller::mainLoop() {
    while (window->IsOpened()) {
        update();
        drawScene();
    }
}

void Controller::processEvents() {
    sf::Event Event;
    while (window->GetEvent(Event)) {
        if (Event.Type == sf::Event::Closed) {
            window->Close();
        }
    }
}

void Controller::update() {
    processEvents();
    
    elapsedTime = window->GetFrameTime();
        
    // Update objects
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects.at(i)->update(elapsedTime);
    }
    
    if (window->GetInput().IsKeyDown(sf::Key::Left)) {
    
    }
    
    if (window->GetInput().IsKeyDown(sf::Key::Right)) {
        
    }
    
    cpSpaceStep(space, elapsedTime);
}

void Controller::drawScene() {
    window->Clear();
    
    // Draw all of the game objects
    for (int i = 0; i < gameObjects.size(); i++) {
        renderer->render(gameObjects.at(i));
    }
    window->Display();
}

void Controller::initializeObjects() {
    cpVect gravity = cpv(0, 1000);
    space = cpSpaceNew();
    cpSpaceSetGravity(space, gravity);
    
    // Add a static line segment shape for the ground.
     // We'll make it slightly tilted so the ball will roll off.
     // We attach it to space->staticBody to tell Chipmunk it shouldn't be movable.
     ground = cpSegmentShapeNew(space->staticBody, cpv(-10, 300), cpv(400, 350), 0);
     cpShapeSetFriction(ground, FRICTION_CONSTANT);
     cpSpaceAddShape(space, ground);
     
    
    GameObject* obj = new GameObject();
    sf::Image* img = resourceHandler->getImage("bird");
    obj->addComponent(new RenderableComponent(img), COMP_TYPE_RENDERABLE);
    obj->addComponent(new BoxPhysicsComponent(10, 50, 50, 1), COMP_TYPE_PHYSICS);
    PhysicsComponent* comp = (PhysicsComponent*) obj->getComponent(COMP_TYPE_PHYSICS);
    comp->addToSpace(space);
    gameObjects.push_back(obj);
}