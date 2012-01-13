/*
 *  InputComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 1/13/12.
 *  Copyright 2012 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Component.h"
#include <map>
#include <SFML/Graphics.hpp>


class InputHandler;

class InputComponent : public Component {
protected:
    InputHandler* handler;
    
public:
    virtual void update() = 0;
};
