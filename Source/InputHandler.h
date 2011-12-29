/*
 *  InputHandler.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>

typedef sf::Vector2f vec2;

class InputComponent;

class InputHandler {
private:
    sf::RenderWindow* window;
    
public:
    InputHandler(sf::RenderWindow* window);
    void update();
    
    bool isKeyDown(sf::Key::Code code);
    vec2 getMousePosition();
    bool isMouseButtonDown(sf::Mouse::Button button);
};
