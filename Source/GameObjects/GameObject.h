/*
 *  GameObject.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Constants.h"

class PhysicsComponent;
class RenderableComponent;
class InputComponent;
class Component;

class GameObject {
protected:
    PhysicsComponent* physicsComponent;
    RenderableComponent* renderableComponent;
    InputComponent* inputComponent;
    
public:
    GameObject();
    ~GameObject();
    
    void update(float elapsedTime);
    
    Component* getComponent(ComponentType type);
    
    void addComponent(Component* comp, ComponentType type);
};
