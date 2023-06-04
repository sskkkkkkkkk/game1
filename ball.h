#ifndef BALL_H
#define BALL_H

#include <SDL.h>

class Ball {
public:
    Ball(SDL_Renderer* renderer, int screenWidth, int screenHeight);

    void Update(float deltaTime);
    void Render();
    bool CheckCollisionWithBlock(SDL_Rect blockRect);
    bool CheckCollisionWithPaddle(SDL_Rect paddleRect);
    void ReverseYVel();
    bool ballTouchtheBottom();
private:
    SDL_Renderer* m_Renderer;
    SDL_Rect m_BallRect;
    float m_PosX;
    float m_PosY;
    float m_VelX;
    float m_VelY;
    float m_Radius;

    void Bounce();
    
};

#endif  // BALL_H
