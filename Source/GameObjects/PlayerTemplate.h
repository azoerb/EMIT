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
#include "AllComponents.h"
#include "InputHandler.h"
#include "ResourceHandler.h"
#include <SFML/Graphics.hpp>
#include "Box2D.h"

class PlayerTemplate : public GameObject {
public:
    GameObject* create(b2World* world, InputHandler* input, ResourceHandler* resource) {
        inputComponent = new PlayerInputComponent(this, input);
        
        physicsComponent = new PhysicsComponent(this, world, 250.0, 0.0, .25, .25, 1.0, .6);
        
        sf::Image* img = resource->getImage("bird");        
        renderableComponent = new RenderableComponent(this, img);
        
        renderableComponent->update(0.0, physicsComponent->getPosition(), 0.0);
        return this;
    }
};
