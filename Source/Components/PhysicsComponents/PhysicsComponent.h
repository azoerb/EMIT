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
#include "Box2D.h"
#include "Constants.h"

typedef sf::Vector2f vec2;

class PhysicsComponent : public Component {
protected:
    b2Body* body;
    b2World* world;
    
public:    
    PhysicsComponent(b2World* world, float x, float y, float height, float width, float density, float friction);
    
    PhysicsComponent(b2World* world, float x, float y, b2Vec2* vertices, int numVerts, float density, float friction);
    
    ~PhysicsComponent();
    
    vec2 getPosition();
    
    vec2 getLinearVelocity();
    
    float getRotation();
    
    void setPosition(vec2 pos);
    
    void setVelocity(vec2 vel);
    
    void changePosition(vec2 offset);
    
    void changeVelocity(vec2 offset);
    
    void update(float elapsedTime);
};
