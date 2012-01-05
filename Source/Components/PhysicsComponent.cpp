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

void PhysicsComponent::setBody(vec2 pos, float angle) {
    body->SetTransform(b2Vec2(pos.x, pos.y), angle * PI / 180);
}

void PhysicsComponent::setVelocity(vec2 vel) {
    
}

void PhysicsComponent::update(float elapsedTime) {
}