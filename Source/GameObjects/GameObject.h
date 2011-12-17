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

using sf::Vector2f;

class GameObject {
private:
    PhysicsComponent* physicsComponent;
    RenderableComponent* renderableComponent;
    
public:
    GameObject() {
        
    }
    
    ~GameObject() {
        if (physicsComponent) { delete physicsComponent; }
        if (renderableComponent) { delete renderableComponent; }
    }
    
    void update(float elapsedTime) {
        physicsComponent->update(elapsedTime);
        
        cpVect pos = physicsComponent->getPosition();
        cpVect rot = physicsComponent->getRotation();
        renderableComponent->update(elapsedTime, Vector2f(pos.x, pos.y), Vector2f(rot.x, rot.y));
    }
    
    Component* getComponent(ComponentType type) {
        switch (type) {
            case COMP_TYPE_RENDERABLE:
                return renderableComponent;
                break;
                
            case COMP_TYPE_PHYSICS:
                return physicsComponent;
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
        }
    }
};
