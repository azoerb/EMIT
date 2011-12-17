/*
 *  Renderer.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "Renderer.h"
#include "GameObject.h"

Renderer::Renderer(sf::RenderWindow* window) {
    this->window = window;
}

Renderer::~Renderer() {
}

void Renderer::render(GameObject* obj) {
    RenderableComponent* comp = (RenderableComponent*) obj->getComponent(COMP_TYPE_RENDERABLE);
    if (comp) {
        window->Draw(*comp->getSprite());
    }
}
