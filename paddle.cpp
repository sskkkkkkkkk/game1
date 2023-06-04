#include "paddle.h"
#include"g.h"

Paddle::Paddle(SDL_Renderer* renderer, int screenWidth, int screenHeight)
    : paddleWidth(50),
    paddleHeight(6),
    m_Renderer(renderer),
    paddleVelocity(1)

{
    paddle_Rect.x = (screenWidth - paddleWidth) / 2;
    paddle_Rect.y = screenHeight - 20;
    paddle_Rect.w = paddleWidth;
    paddle_Rect.h = paddleHeight;
}




void Paddle::Render() {
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_Renderer, &paddle_Rect);
}

void Paddle::handleInput() {
    // Move the paddle left or right based on keyboard input
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_LEFT] && paddle_Rect.x > 0) {
        paddle_Rect.x -= paddleVelocity;
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT] && paddle_Rect.x + paddle_Rect.w < SCREEN_WIDTH) {
        paddle_Rect.x += paddleVelocity;
    }
}

SDL_Rect Paddle::getPaddle() {
    return paddle_Rect;
}
