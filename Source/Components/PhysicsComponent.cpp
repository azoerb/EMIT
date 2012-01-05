/*
 *  PhysicsComponent.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 1/3/12.
 *  Copyright 2012 Zoerbsoft. All rights reserved.
 *
 */

#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(b2World* world, float x, float y, float height, float width, float density, float friction) {
    this->world = world;
    
    b2BodyDef bodyDef;
    if (density > 0.0) {
        bodyDef.type = b2_dynamicBody;
    }
    bodyDef.position.Set(x / PIXELS_PER_METER, y / PIXELS_PER_METER);
    
    body = world->CreateBody(&bodyDef);
    
    b2PolygonShape box;
    box.SetAsBox(height, width);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = density;    
    fixtureDef.friction = friction;
    
    body->CreateFixture(&fixtureDef);
}

PhysicsComponent::PhysicsComponent(b2World* world, float x, float y, b2Vec2* vertices, int numVerts, float density, float friction) {
    this->world = world;
    
    b2BodyDef bodyDef;
    if (density > 0.0) {
        bodyDef.type = b2_dynamicBody;
    }
    bodyDef.position.Set(x / PIXELS_PER_METER, y / PIXELS_PER_METER);
    
    body = world->CreateBody(&bodyDef);
    
    b2PolygonShape shape;
    shape.Set(vertices, numVerts);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = density;    
    fixtureDef.friction = friction;
    
    body->CreateFixture(&fixtureDef);
}

PhysicsComponent::~PhysicsComponent() {
    if (body) { world->DestroyBody(body); }
}

vec2 PhysicsComponent::getPosition() {
    b2Vec2 pos = body->GetPosition();
    return vec2(pos.x * PIXELS_PER_METER, pos.y * PIXELS_PER_METER);
}

vec2 PhysicsComponent::getLinearVelocity() {
    b2Vec2 vel = body->GetLinearVelocity();
    return vec2(vel.x, vel.y);
}

float PhysicsComponent::getRotation() {
    return body->GetAngle() * 180 / PI;
}

void PhysicsComponent::setPosition(vec2 pos) {

}

void PhysicsComponent::setVelocity(vec2 vel) {
    
}

void PhysicsComponent::changePosition(vec2 offset) {
    vec2 pos = getPosition();
    pos.x += offset.x;
    pos.y += offset.y;
    setPosition(pos);
}

void PhysicsComponent::changeVelocity(vec2 offset) {
    vec2 vel = getLinearVelocity();
    vel.x += offset.x;
    vel.y += offset.y;
    setVelocity(vel);
}

void PhysicsComponent::update(float elapsedTime) {
}