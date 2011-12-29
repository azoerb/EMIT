/*
 *  InputComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Component.h"
#include "chipmunk.h"

class InputHandler;

class InputComponent : public Component {
private:
    InputHandler* handler;
    
public:
    void registerHandler(InputHandler* handler);
    cpVect update();
};
