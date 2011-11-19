/*
 *  LevelObject.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/8/11.
 *  Copyright 2011 Door 6. All rights reserved.
 *
 */

#pragma once

#define vec2 sf::Vector2f

class LevelObject {
private:
    vec2 position;
    vec2 dimensions;
    
    sf::Image* image;
    sf::Sprite* sprite;
    
    int lastIndex;
    std::vector<vec2> points;
    
public:
    LevelObject(sf::Image* img) {
        image = img;
        sprite = new sf::Sprite();
        sprite->SetImage(*img);
        
        dimensions = vec2(img->GetWidth(), img->GetHeight());
    }
    
    vec2 getPosition() { return position; }
    void setPosition(vec2 pos) { position = pos; }
    void changePosition(vec2 offset) { position += offset; }
    
    vec2 getDimensions() { return dimensions; }
    void setDimensions(vec2 dim) { dimensions = dim; }
    
    sf::Sprite* getSprite() {
        update();
        return sprite;
    }
    
    void update() {
        sprite->SetPosition(position);
    }
    
    void setLastIndex(int index) { lastIndex = index; }
    int getLastIndex() { return lastIndex; }
    
    std::vector<vec2> getPoints() { return points; }
    void setPoints(std::vector<vec2> newPoints) { points = newPoints; }
};