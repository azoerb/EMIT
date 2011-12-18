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
    sprite->SetCenter(img->GetWidth() / 2, img->GetHeight() / 2);
}

RenderableComponent::~RenderableComponent() {

}

void RenderableComponent::setImage(sf::Image* img) {
    sprite->SetImage(*img);
}

sf::Sprite* RenderableComponent::getSprite() {
    return sprite;
}

void RenderableComponent::update(float elapsedTime, Vector2f pos, float rot) {
    updateSprite(pos, rot);
}

void RenderableComponent::updateSprite(Vector2f pos, float rot) {
    sprite->SetPosition(pos.x, pos.y);
    sprite->SetRotation(rot);
}