/*
 *  InputHandler.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "InputHandler.h"
#include "InputComponent.h"

void InputHandler::registerComponent(InputComponent* comp) {
    components.push_back(comp);
}
