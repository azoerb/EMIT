/*
 *  BoxPhysicsComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "PhysicsComponent.h"

class BoxPhysicsComponent : public PhysicsComponent {
private:
    
public:
    BoxPhysicsComponent(float mass, float width, float height, float friction);
};
