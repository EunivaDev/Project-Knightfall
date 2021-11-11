#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    RenderWindow();
    void createWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);

    void render(Entity& p_entity);
    void render(float p_x, float p_y, SDL_Texture* p_tex);
    void render(SDL_Texture* p_tex);
    void clear();
    void display();
    void cleanUp();
};