/*
 *  main.cpp
 *  EMIT
 *
 *  Created by Andrew Zoerb on 11/7/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 */

#include "Controller.h"

int main() {
    Controller* game = new Controller();
    
    game->mainLoop();

    if (game) { delete game; }
    return EXIT_SUCCESS;
}
