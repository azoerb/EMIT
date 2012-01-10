/*
 *  PlayerTemplate.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 1/6/12.
 *  Copyright 2012 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "GameObject.h"
#include "InputHandler.h"
#include "ResourceHandler.h"
#include <SFML/Graphics.hpp>
#include "Box2D.h"

class PlayerTemplate : public GameObject {
private:
    void (PlayerTemplate::*rightPointer) ();
    void (PlayerTemplate::*leftPointer) ();
    
    void actionRight() {
        vec2 pos = physicsComponent->getPosition();
        printf("%f, %f\n", pos.x, pos.y);
    }
    
    void actionLeft() {
        printf("LEFT!!!!!\n");
    }
public:
    PlayerTemplate() {
        rightPointer = &PlayerTemplate::actionRight;
        leftPointer = &PlayerTemplate::actionLeft;
    }
    
    GameObject* create(b2World* world, InputHandler* input, ResourceHandler* resource) {
        inputComponent = new InputComponent(input);
        
        /*inputComponent->assignAction(sf::Key::Right, &PlayerTemplate::actionRight);
        inputComponent->assignAction(sf::Key::Left, &PlayerTemplate::actionLeft);*/
        
        physicsComponent = new PhysicsComponent(world, 250.0, 0.0, .25, .25, 1.0, .6);
        
        sf::Image* img = resource->getImage("bird");        
        renderableComponent = new RenderableComponent(img);
        
        renderableComponent->update(0.0, physicsComponent->getPosition(), 0.0);
        return this;
    }
    
    void test() {
        (this->*rightPointer)();
    }
};
