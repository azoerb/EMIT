/*
 *  Constants.h
 *  EMIT
 *
 *  Created by Andrew Zoerb on 12/16/11.
 *  Copyright 2011 Zoerbsoft. All rights reserved.
 *
 */

#pragma once

enum ComponentType {
    COMP_TYPE_PHYSICS = 0,
    COMP_TYPE_RENDERABLE,
    COMP_TYPE_INPUT,
    NUM_COMP_TYPES
};

const float PI = 3.1415;

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

const int VELOCITY_ITERATIONS = 8;
const int POSITION_ITERATIONS = 3;
const float TIME_STEP = 1.0 / 60.0;
const float TIME_STEP_SLOW_FACTOR = 1.0;

const float PIXELS_PER_METER = 35;
