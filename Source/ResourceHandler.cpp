/*
 *  ResourceHandler.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#include "ResourceHandler.h"

ResourceHandler::ResourceHandler() {
    
}

ResourceHandler::~ResourceHandler() {
    imageMap::iterator iter;
    for (iter = images.begin(); iter != images.end(); iter++) {
        if (iter->second) { delete iter->second; }
    }
}

Image* ResourceHandler::loadImageFromFile(string name, string filePath) {
    Image* image = new Image();
    if (!image->LoadFromFile(filePath)) {
        // For now just print an error
        printf("Error loading image from file");
    }
    images.insert(imagePair(name, image));
    return image;
}

void ResourceHandler::loadResources() {
    loadImageFromFile("bird", "../Resources/Bird.png");
}

Image* ResourceHandler::getImage(string name) {
    imageMap::iterator iter;
    iter = images.find(name);
    return iter->second;
}