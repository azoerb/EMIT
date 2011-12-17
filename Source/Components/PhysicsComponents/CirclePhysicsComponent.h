/*
 *  CirclePhysicsComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "PhysicsComponent.h"

class CirclePhysicsComponent : public PhysicsComponent {
private:
    
public:
    CirclePhysicsComponent(float mass, float radius, float friction);
};