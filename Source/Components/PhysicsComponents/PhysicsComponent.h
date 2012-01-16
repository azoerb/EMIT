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

typedef sf::Vector2f vec2;

class PhysicsComponent : public Component {
protected:
    b2Body* body;
    b2World* world;
    
public:    
    PhysicsComponent(GameObject* parent, b2World* world, float x, float y, float height, float width, float density, float friction);
    
    PhysicsComponent(GameObject* parent, b2World* world, float x, float y, b2Vec2* vertices, int numVerts, float density, float friction);
    
    ~PhysicsComponent();
    
    vec2 getPosition();
    
    vec2 getLinearVelocity();
    
    float getRotation();
    
    void setBody(vec2 pos, float angle);
    
    void setVelocity(vec2 vel);
    
    void applyImpulse(b2Vec2 impulse);
        
    void update(float elapsedTime);
};
