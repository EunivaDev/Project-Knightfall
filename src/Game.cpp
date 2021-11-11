#include "Game.hpp"
#include "Levels.hpp"
#include "RenderWindow.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "Ground.hpp"
#include "FrameControl.hpp"
#include "Math.hpp"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>



// INTIALIZE
RenderWindow window;
bool gameRunning;

// Textures
SDL_Texture* stone_ground;
SDL_Texture* stone_wall;
SDL_Texture* playerTex;


// CONSTANTS
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;



bool initGame()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. .Error: " << SDL_GetError() << std:: endl;
    
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    window.createWindow("Project: Knightfall", SCREEN_WIDTH, SCREEN_HEIGHT);

    initTextures();

    std::cout << "Code: Game Initialized" << std::endl;

    return true;
}

void initTextures()
{
    // Render Ground Entities
    stone_ground = window.loadTexture("res/textures/stone/stone_ground.png");
    stone_wall = window.loadTexture("res/textures/stone/stone_wall.png");

    // Render Player
    playerTex = window.loadTexture("res/textures/player/player_1.png");

    std::cout << "Code: Textures Initialized" << std::endl;
}


bool load = initGame();

// PLAYER
Vector2f playerPos(32, 170);
Player player(playerPos, playerTex);
Entity stone(32, 32, stone_ground);


void runGame()
{
    gameRunning = true;
    
    while (gameRunning)
    {
        Uint32 frameStart = SDL_GetTicks();
        int frameTime;

        processGame();
        
        frameControl(frameStart, frameTime);
    }
    
    window.cleanUp();
    SDL_Quit();
}

void processGame()
{
    SDL_Event event;

    processInput(event);
    processPlayer(event);

    window.clear();
    player.update();
    window.render(player);
    window.render(stone);
    window.display();
}

void processPlayer(SDL_Event& event)
{
    while (SDL_PollEvent(&event))
    {

    
    switch (event.type)
    { // ..... SWITCH START - event.type
    case SDL_QUIT:
    {
        gameRunning = false;
        break;
    }
    case SDL_KEYDOWN:
    {
        switch(event.key.keysym.scancode)
        {   // ..... SWITCH START - event.key.keysym.scancode
        case SDL_SCANCODE_UP:       // ... UP
        {
            player.jump();
            break;
        }
        case SDL_SCANCODE_DOWN:     // ... DOWN
        {
            player.setGrounded();
            break;
        }
        case SDL_SCANCODE_LEFT:     // ... LEFT
        {
            if (player.getVelX() != 1)
                player.setVelX(-1);
            else
                player.setVelX(0);
            break;
        }
        case SDL_SCANCODE_RIGHT:    // ... RIGHT
        {
            if (player.getVelX() != -1)
                player.setVelX(1);
            else
                player.setVelX(0);
            break;
        }
        case SDL_SCANCODE_SPACE:    // ... JUMP
        {
            player.jump();
            break;
        }

        }   // ..... SWITCH END - event.key.keysym.scancode
    }

    }   // ..... SWITCH END - event.type
    }
}

void processInput(SDL_Event& event)
{
    return;
}