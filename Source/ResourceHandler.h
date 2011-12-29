/*
 *  ResourceHandler.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

#include <SFML/Graphics.hpp>

using std::string;
using sf::Image;

typedef std::pair<string, Image*> imagePair;
typedef std::map<string, Image*> imageMap;

class ResourceHandler {
private:
    imageMap images;
    
    Image* loadImageFromFile(string name, string filePath);
    
public:
    ResourceHandler();
    ~ResourceHandler();
    void loadResources();
    
    Image* getImage(string name);
};
