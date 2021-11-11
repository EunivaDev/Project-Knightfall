#pragma once

#include "Levels.hpp"
#include "RenderWindow.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Ground.hpp"
#include "FrameControl.hpp"
#include "Math.hpp"
#include <SDL.h>
#include <SDL_image.h>

bool initGame();
void initTextures();
void runGame();

void processGame();
void processPlayer(SDL_Event& event);
void processInput(SDL_Event& event);