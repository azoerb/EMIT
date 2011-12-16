/*
 *  GameObject.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Door 6. All rights reserved.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>

#define vec2 sf::Vector2f

class GameObject {
private:
    vec2 position;
    vec2 velocity;
    vec2 dimensions;
    
    sf::Image* image;
    sf::Sprite* sprite;
    
    std::vector<vec2> points;
    
public:
    GameObject(sf::Image* img) {
        image = img;
        sprite = new sf::Sprite();
        sprite->SetImage(*img);
        
        position = vec2(0.0, 0.0);
        velocity = vec2(0.0, 0.0);
        dimensions = vec2(img->GetWidth(), img->GetHeight());
    }
    
    GameObject(sf::Image* img, vec2 pos, vec2 vel) {
        image = img;
        sprite = new sf::Sprite();
        sprite->SetImage(*img);
        
        position = pos;
        velocity = vel;
        dimensions = vec2(img->GetWidth(), img->GetHeight());
    }
    
    vec2 getPosition() { return position; }
    void setPosition(vec2 pos) { position = pos; }
    void changePosition(vec2 offset) { position += offset; }
    
    vec2 getVelocity() { return velocity; }
    void setVelocity(vec2 vel) { velocity = vel; }
    void changeVelocity(vec2 offset) { velocity += offset; }
    
    vec2 getDimensions() { return dimensions; }
    void setDimensions(vec2 dim) { dimensions = dim; }
    
    std::vector<vec2> getPoints() {
        std::vector<vec2> newPoints = std::vector<vec2>(points);
        vec2 newPosition = position;
        for (int i = 0; i < newPoints.size(); i++) {
            newPoints[i] += newPosition;
        }
        return newPoints;
    }
    
    void setPoints(std::vector<vec2> newPoints) {
        points = std::vector<vec2>(newPoints);
    }
    
    sf::Sprite* getSprite() {
        update();
        return sprite;
    }
    
    void update() {
        sprite->SetPosition(position);
    }
};
