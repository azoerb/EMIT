/*
 *  Component.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

enum ComponentType {
    COMP_TYPE_PHYSICS = 0,
    COMP_TYPE_RENDERABLE,
    NUM_COMP_TYPES
};

class GameObject;

class Component {
protected:
	GameObject* parent;
    
public:
	inline GameObject* getParent() { return parent; }
    inline void setParent(GameObject* parent) { this->parent = parent; }
};
