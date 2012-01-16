/*
 *  Component.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "GameObject.h"

class Component {
protected:
	GameObject* parent;
    
public:
    Component(GameObject* parent) { this->parent = parent; }
	inline GameObject* getParent() { return parent; }
    inline void setParent(GameObject* parent) { this->parent = parent; }
};
