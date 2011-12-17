/*
 *  Renderer.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Constants.h"
#include <SFML/Graphics.hpp>

class GameObject;

class Renderer {
private:
    sf::RenderWindow* window;
public:
    Renderer(sf::RenderWindow* window);
    ~Renderer();
    
    void render(GameObject* obj);
};
