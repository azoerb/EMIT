/*
 *  CirclePhysicsComponent.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "CirclePhysicsComponent.h"

CirclePhysicsComponent::CirclePhysicsComponent(float mass, float radius, float friction) {
    
    float moment = cpMomentForCircle(mass, 0, radius, cpvzero);
    body = cpBodyNew(mass, moment);
    shape = cpCircleShapeNew(body, radius, cpvzero);
    
    // Set the object's position and friction
    cpBodySetPos(body, cpv(0, 0));
    cpShapeSetFriction(shape, friction);
}
