/*
 *  RenderableComponent.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "RenderableComponent.h"

RenderableComponent::RenderableComponent(sf::Image* img) {
    sprite = new sf::Sprite();
    setImage(img);
}

RenderableComponent::~RenderableComponent() {

}

void RenderableComponent::setImage(sf::Image* img) {
    sprite->SetImage(*img);
}

sf::Sprite* RenderableComponent::getSprite() {
    return sprite;
}

void RenderableComponent::update(float elapsedTime, sf::Vector2f pos) {
    updatePosition(pos);
}

void RenderableComponent::updatePosition(sf::Vector2f pos) {
    sprite->SetPosition(pos.x, pos.y);
}