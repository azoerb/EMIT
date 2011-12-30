/*
 *  PhysicsComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>

typedef sf::Vector2f vec2;

class PhysicsComponent : public Component {
protected:
    
public:
    PhysicsComponent() {}
    
    ~PhysicsComponent() {}
    
    vec2 getPosition() {
    }
    
    vec2 getVelocity() {
    }
    
    vec2 getRotation() {
    }
    
    void setPosition(vec2 pos) {
    }
    
    void setVelocity(vec2 vel) {
    }
    
    void changePosition(vec2 offset) {
        vec2 pos = getPosition();
        pos.x += offset.x;
        pos.y += offset.y;
        //cpBodySetPos(body, pos);
    }
    
    void changeVelocity(vec2 offset) {
        vec2 vel = getVelocity();
        vel.x += offset.x;
        vel.y += offset.y;
        //cpBodySetVel(body, vel);
    }
    
    void update(float elapsedTime) {
    }
};
