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

void RenderableComponent::update(float elapsedTime, Vector2f pos, Vector2f rot) {
    updateSprite(pos, rot);
}

void RenderableComponent::updateSprite(Vector2f pos, Vector2f rot) {
    sprite->SetPosition(pos.x, pos.y);
    sprite->SetRotation(rot.x);
}