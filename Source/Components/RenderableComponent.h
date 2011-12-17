/*
 *  RenderableComponent.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>

using sf::Vector2f;

class RenderableComponent : public Component {
private:
    sf::Sprite* sprite;
    
    void updateSprite(Vector2f pos, Vector2f rot);
    
public:
    RenderableComponent(sf::Image* img);
    ~RenderableComponent();
    
    void setImage(sf::Image* img);
    
    sf::Sprite* getSprite();
    
    void update(float elapsedTime, Vector2f pos, Vector2f rot);
};
