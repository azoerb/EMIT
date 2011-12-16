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
#include <stdio.h>

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
    
    // cpVect is a 2D vector and cpv() is a shortcut for initializing them.
    cpVect gravity = cpv(0, .001);
    
    // Create an empty space.
    space = cpSpaceNew();
    cpSpaceSetGravity(space, gravity);
    
    // Add a static line segment shape for the ground.
    // We'll make it slightly tilted so the ball will roll off.
    // We attach it to space->staticBody to tell Chipmunk it shouldn't be movable.
    ground = cpSegmentShapeNew(space->staticBody, cpv(-10, 300), cpv(400, 350), 0);
    cpShapeSetFriction(ground, FRICTION_CONSTANT);
    cpSpaceAddShape(space, ground);
    
    // Now let's make a ball that falls onto the line and rolls off.
    // First we need to make a cpBody to hold the physical properties of the object.
    // These include the mass, position, velocity, angle, etc. of the object.
    // Then we attach collision shapes to the cpBody to give it a size and shape.
    
    cpFloat radius = 5;
    cpFloat mass = .0001;
    
    // The moment of inertia is like mass for rotation
    // Use the cpMomentFor*() functions to help you approximate it.
    cpFloat moment = cpMomentForBox(mass, radius, radius);
    
    // The cpSpaceAdd*() functions return the thing that you are adding.
    // It's convenient to create and add an object in one line.
    ballBody = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    cpBodySetPos(ballBody, cpv(50, 15));
    
    // Now we create the collision shape for the ball.
    // You can create multiple collision shapes that point to the same body.
    // They will all be attached to the body and move around to follow it.
    ballShape = cpSpaceAddShape(space, cpBoxShapeNew(ballBody, radius, radius));
    cpShapeSetFriction(ballShape, 0.7);    
}

Controller::~Controller() {
    if (window) { delete window; }
    if (birdImg) { delete birdImg; }
    if (bird) { delete bird; }
    if (mapImg) { delete mapImg; }
    if (map) { delete map; }
    
    
    // Clean up our objects and exit!
    cpShapeFree(ballShape);
    cpBodyFree(ballBody);
    cpShapeFree(ground);
    cpSpaceFree(space);
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
        
    // Now that it's all set up, we simulate all the objects in the space by
    // stepping forward through time in small increments called steps.
    // It is *highly* recommended to use a fixed size time step.
    cpFloat timeStep = 1.0/60.0;
    for(cpFloat time = 0; time < 2; time += timeStep){
        cpVect pos = cpBodyGetPos(ballBody);
        cpVect vel = cpBodyGetVel(ballBody);
        printf("%f, %f\n", pos.x, pos.y);
        bird->setPosition(vec2(pos.x, pos.y));
        
        cpSpaceStep(space, timeStep);
    }
            
/*    // Move the sprite
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
*/
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
    mapPoints.push_back(vec2(20, WINDOW_HEIGHT - 100));
    mapPoints.push_back(vec2(500, WINDOW_HEIGHT - 200));
    map->setPoints(mapPoints);
}