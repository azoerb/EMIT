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
    
    // Define the gravity vector.
	b2Vec2 gravity(0.0f, -10.0f);
    
	// Construct a world object, which will hold and simulate the rigid bodies.
	world = new b2World(gravity);
    
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
    
	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundBody = world->CreateBody(&groundBodyDef);
    
	// Define the ground box shape.
	b2PolygonShape groundBox;
    
	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);
    
	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
    
	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	body = world->CreateBody(&bodyDef);
    
	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
    
	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
    
	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;
    
	// Override the default friction.
	fixtureDef.friction = 0.3f;
    
	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
}

Controller::~Controller() {
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
    
    world->Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
    
    // Now print the position and angle of the body.
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();
    
    printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
            
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
    window->Display();
}

void Controller::initializeObjects() {
    GameObject* obj = new GameObject();
    sf::Image* img = resourceHandler->getImage("bird");
    addComponent(obj, new InputComponent(), COMP_TYPE_INPUT);
    addComponent(obj, new RenderableComponent(img), COMP_TYPE_RENDERABLE);
    //addComponent(obj, new BoxPhysicsComponent(100, 50, 50, .95), COMP_TYPE_PHYSICS);
    //PhysicsComponent* comp = (PhysicsComponent*) obj->getComponent(COMP_TYPE_PHYSICS);
    //comp->addToSpace(space);
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