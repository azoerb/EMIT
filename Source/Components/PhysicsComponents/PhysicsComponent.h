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
#include <chipmunk.h>

class PhysicsComponent : public Component {
protected:
    cpBody* body;
    cpShape* shape;
    
public:
    PhysicsComponent() {}
    
    ~PhysicsComponent() {
        cpShapeFree(shape);
        cpBodyFree(body);
    }
    
    void addToSpace(cpSpace* space) {
        cpSpaceAddBody(space, body);
        cpSpaceAddShape(space, shape);
    }
    
    cpVect getPosition() {
        return cpBodyGetPos(body); 
    }
    
    cpVect getVelocity() {
        return cpBodyGetVel(body);   
    }
    
    void setPosition(cpVect pos) {
        cpBodySetPos(body, pos);
    }
    
    void setVelocity(cpVect vel) {
        cpBodySetVel(body, vel);
    }
    
    void changePosition(cpVect offset) {
        cpVect pos = getPosition();
        pos.x += offset.x;
        pos.y += offset.y;
        cpBodySetPos(body, pos);
    }
    
    void changeVelocity(cpVect offset) {
        cpVect vel = getVelocity();
        vel.x += offset.x;
        vel.y += offset.y;
        cpBodySetVel(body, vel);
    }
    
    void update(float elapsedTime) {
        
    }
};
