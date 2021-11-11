#pragma once

#include <SDL.h>

const int MAX_FPS = 60;
const int FRAME_DELAY = 1000 / MAX_FPS;


void frameControl(Uint32& frameStart, int& frameTime);