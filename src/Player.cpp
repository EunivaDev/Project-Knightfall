#include "Player.hpp"
#include "Entity.hpp"
#include "Ground.hpp"
#include "Math.hpp"

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

const float GRAVITY = 0.2f;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Player::Player(Vector2f p_pos, SDL_Texture* p_tex) : Entity{p_pos, p_tex}, grounded(true)
{}

Player::Player(float p_x, float p_y, SDL_Texture* p_tex) : Entity{p_x, p_y, p_tex}, grounded(true)
{}

void Player::jump()
{
    if (grounded)
    {
        jumping = true;
        grounded = false;
        vel.y = -4;
    }
}

bool Player::isJumping()
{
    return jumping;
}

void Player::setJumping()
{
    jumping = true;
}

bool Player::isGrounded()
{
    return grounded;
}

void Player::setGrounded()
{
    grounded = true;
}

void Player::update()
{
    setX(getX() + vel.x * playerSpeed);
    setY(getY() + vel.y * 2);
    if (!grounded)
    {
        vel.y += GRAVITY;
    }
    else
    {
        vel.y = 0;
    }
}

void Player::setVelocity(Vector2f p_vel)
{
    vel = p_vel;
}

float Player::getVelX()
{
    return vel.x;
}

float Player::getVelY()
{
    return vel.y;
}

void Player::setVelX(float v_x)
{
    vel.x = v_x;
}

void Player::setVelY(float v_y)
{
    vel.y = v_y;
}