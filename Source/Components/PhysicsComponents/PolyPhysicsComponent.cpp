/*
 *  PolyPhysicsComponent.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "PolyPhysicsComponent.h"

PolyPhysicsComponent::PolyPhysicsComponent(float mass, int numVerts, cpVect* verts, cpVect offset, float friction) {
    
    float moment = cpMomentForPoly(mass, numVerts, verts, offset);
    body = cpBodyNew(mass, moment);
    shape = cpPolyShapeNew(body, numVerts, verts, offset);
    
    // Set the object's position and friction
    cpBodySetPos(body, cpv(0, 0));
    cpShapeSetFriction(shape, friction);
}