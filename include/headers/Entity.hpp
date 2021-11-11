#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"

class Entity
{
private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float getX();
    float getY();
    Vector2f& getPos();
    int getWidth();
    int getHeight();
    void setX(float p_x);
    void setY(float p_y);
    void setPos(Vector2f p_pos);
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();

};