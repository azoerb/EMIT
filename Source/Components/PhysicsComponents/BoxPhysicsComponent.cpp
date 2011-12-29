/*
 *  BoxPhysicsComponent.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "BoxPhysicsComponent.h"

BoxPhysicsComponent::BoxPhysicsComponent(float mass, float width, float height, float friction) {
    
    float moment = INFINITY; //cpMomentForBox(mass, width, height);
    body = cpBodyNew(mass, moment);
    shape = cpBoxShapeNew(body, width, height);
    
    // Set the object's position and friction
    cpBodySetPos(body, cpv(0, 0));
    cpShapeSetFriction(shape, friction);
}
