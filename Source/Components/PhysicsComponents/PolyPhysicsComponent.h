/*
 *  PolyPhysicsComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "PhysicsComponent.h"

class PolyPhysicsComponent : public PhysicsComponent {
private:
    
public:
    PolyPhysicsComponent(float mass, int numVerts, vec2* verts, vec2 offset, float friction);
};
