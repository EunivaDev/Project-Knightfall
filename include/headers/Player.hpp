#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"
#include "Ground.hpp"

class Player : public Entity
{
private:
    Vector2f vel;
    float playerSpeed = 3.0;
    float jumpHeight = 96;
    float displacement = 0;
    bool grounded;
    bool jumping;

public:
    Player(Vector2f p_pos, SDL_Texture* p_tex);
    Player(float p_x, float p_y, SDL_Texture* p_tex);
    void jump();
    bool isJumping();
    void setJumping();
    bool isGrounded();
    void setGrounded();
    void update();
    void setVelocity(Vector2f p_vel);
    float getVelX();
    float getVelY();
    void setVelX(float v_x);
    void setVelY(float v_y);
};