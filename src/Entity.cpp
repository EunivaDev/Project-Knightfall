#include "Entity.hpp"
#include "Math.hpp"
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex) : pos(p_pos), texture(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex) : pos(p_x, p_y), texture(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

float Entity::getX()
{
    return pos.x;
}

float Entity::getY()
{
    return pos.y;
}

Vector2f& Entity::getPos()
{
    return pos;
}

int Entity::getWidth()
{
    return currentFrame.w;
}

int Entity::getHeight()
{
    return currentFrame.h;
}

void Entity::setX(float p_x)
{
    pos.x = p_x;
}

void Entity::setY(float p_y)
{
    pos.y = p_y;
}

void Entity::setPos(Vector2f p_pos)
{
    pos = p_pos;
}

SDL_Texture* Entity::getTexture()
{
    return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}