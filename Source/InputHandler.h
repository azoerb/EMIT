/*
 *  InputHandler.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include <vector>

class InputComponent;

class InputHandler {
private:
    std::vector<InputComponent*> components;
    
public:
    void registerComponent(InputComponent* comp);
};
