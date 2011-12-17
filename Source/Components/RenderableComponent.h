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

class RenderableComponent : public Component {
private:
    sf::Sprite* sprite;
    
    void updatePosition(sf::Vector2f pos);
    
public:
    RenderableComponent(sf::Image* img);
    ~RenderableComponent();
    
    void setImage(sf::Image* img);
    
    sf::Sprite* getSprite();
    
    void update(float elapsedTime, sf::Vector2f pos);
};
