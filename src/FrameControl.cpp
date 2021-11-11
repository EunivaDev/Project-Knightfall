#include "FrameControl.hpp"

#include <SDL.h>


void frameControl(Uint32& frameStart, int& frameTime)
{
    frameTime = SDL_GetTicks() - frameStart;
    if (FRAME_DELAY > frameTime)
        SDL_Delay(FRAME_DELAY - frameTime);
}