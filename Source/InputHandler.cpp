/*
 *  InputHandler.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/18/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "InputHandler.h"
#include "InputComponent.h"

InputHandler::InputHandler(sf::RenderWindow* window) {
    this->window = window;
}

void InputHandler::update() {
    sf::Event Event;
    while (window->GetEvent(Event)) {
        if (Event.Type == sf::Event::Closed) {
            window->Close();
        }
    }
}

bool InputHandler::isKeyDown(sf::Key::Code code) {
    return window->GetInput().IsKeyDown(code);
}

vec2 InputHandler::getMousePosition() {
    return vec2(window->GetInput().GetMouseX(), window->GetInput().GetMouseY());
}

bool InputHandler::isMouseButtonDown(sf::Mouse::Button button) {
    return window->GetInput().IsMouseButtonDown(button);
}
