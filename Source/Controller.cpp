/*
 *  Controller.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "Controller.h"
#include "AllObjects.h"
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
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects.at(i)) { delete gameObjects.at(i); }
    }    
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

    world->Step(TIME_STEP / TIME_STEP_SLOW_FACTOR, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    
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
    
    // Draw the physics debug data
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
    verts[2].Set(10.0, 5.0);
    verts[1].Set(20.0, 5.0);
    floor->addComponent(new PhysicsComponent(floor, world, 100.0, 300.0, verts, 3, 0.0, .6), COMP_TYPE_PHYSICS);
    gameObjects.push_back(floor);
    
    PlayerTemplate* player = new PlayerTemplate();
    gameObjects.push_back(player->create(world, inputHandler, resourceHandler));
}
