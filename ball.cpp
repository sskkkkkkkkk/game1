#include "ball.h"
#include "g.h"


Ball::Ball(SDL_Renderer* renderer, int screenWidth, int screenHeight)
  : m_Renderer(renderer),
    m_PosX(screenWidth / 2),
    m_PosY(screenHeight / 2),
    m_VelX(5),
    m_VelY(-5),
    m_Radius(10) {
    m_BallRect.w = m_BallRect.h = static_cast<int>(m_Radius * 2);
}

void Ball::Update(float deltaTime) {
    m_PosX += m_VelX * deltaTime;
    m_PosY += m_VelY * deltaTime;

    // Bounce logic goes here
    Bounce();
}

void Ball::Render() {
    m_BallRect.x = static_cast<int>(m_PosX - m_Radius);
    m_BallRect.y = static_cast<int>(m_PosY - m_Radius);
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_Renderer, &m_BallRect);
}

void Ball::Bounce() {
    // Check collision with the screen edges
    if (m_PosX - m_Radius <= 0 || m_PosX + m_Radius >= SCREEN_WIDTH) {
        // Reverse the X velocity
        m_VelX = -m_VelX;
    }

    if (m_PosY - m_Radius <= 0) {
        // Reverse the Y velocity
        m_VelY = -m_VelY;
    }

    // Check if the ball went out of bounds (below the screen)
    if (m_PosY + m_Radius >= SCREEN_HEIGHT) {
        // Reset the ball position
        m_PosX = SCREEN_WIDTH / 2;
        m_PosY = SCREEN_HEIGHT / 2;

        // Reset the ball velocity
        m_VelX = 5;
        m_VelY = -5;
    }
}


bool Ball::CheckCollisionWithBlock(SDL_Rect blockRect) {
    // Check collision between the ball and the block
    if (m_PosX + m_Radius >= blockRect.x &&
        m_PosX - m_Radius <= blockRect.x + blockRect.w &&
        m_PosY + m_Radius >= blockRect.y &&
        m_PosY - m_Radius <= blockRect.y + blockRect.h) {
        // Collision detected
        // // Reverse the Y velocity
        //ReverseYVel()
        return true;
       
    }
    return false;
}


void Ball::ReverseYVel() {
    // Reverse the Y velocity
    m_VelY = -m_VelY;
}


bool Ball::CheckCollisionWithPaddle(SDL_Rect paddleRect) {
    if (m_PosX + m_Radius >= paddleRect.x &&
        m_PosX - m_Radius <= paddleRect.x + paddleRect.w &&
        m_PosY + m_Radius >= paddleRect.y &&
        m_PosY - m_Radius <= paddleRect.y + paddleRect.h) {
        // Collision detected
        // // Reverse the Y velocity
        //ReverseYVel()
        return true;

    }
    return false;
}

bool Ball::ballTouchtheBottom() {
    if (m_BallRect.y + m_BallRect.h + 10 >= SCREEN_HEIGHT) {
        return true;
   }
    return false;
}



