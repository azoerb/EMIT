/*
 *  GameObject.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "AllComponents.h"
#include "Constants.h"

using sf::Vector2f;

class GameObject {
private:
    PhysicsComponent* physicsComponent;
    RenderableComponent* renderableComponent;
    InputComponent* inputComponent;
    
public:
    GameObject() {
        physicsComponent = NULL;
        renderableComponent = NULL;
        inputComponent = NULL;
    }
    
    ~GameObject() {
        if (physicsComponent) { delete physicsComponent; }
        if (renderableComponent) { delete renderableComponent; }
        if (inputComponent) { delete inputComponent; }
    }
    
    void update(float elapsedTime) {
        if (inputComponent) {
            inputComponent->update();
        }
        
        if (physicsComponent && renderableComponent) {
            vec2 pos = physicsComponent->getPosition();
            float rot = physicsComponent->getRotation();
            renderableComponent->update(elapsedTime, pos, rot);
        }
    }
    
    Component* getComponent(ComponentType type) {
        switch (type) {
            case COMP_TYPE_RENDERABLE:
                return renderableComponent;
                break;
                
            case COMP_TYPE_PHYSICS:
                return physicsComponent;
                break;
                
            case COMP_TYPE_INPUT:
                return inputComponent;
                break;
        }
        
    }
    
    void addComponent(Component* comp, ComponentType type) {
        switch (type) {
            case COMP_TYPE_RENDERABLE:
                renderableComponent = (RenderableComponent*) comp;
                break;
                
            case COMP_TYPE_PHYSICS:
                physicsComponent = (PhysicsComponent*) comp;
                break;
                
            case COMP_TYPE_INPUT:
                inputComponent = (InputComponent*) comp;
                break;
        }
    }
};
