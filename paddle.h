#ifndef PADDLE_H
#define PADDLE_H

#include <SDL.h>

class Paddle {
public:
	Paddle(SDL_Renderer *renderer,int screenWidth, int screenHeight);
	void handleInput();
	SDL_Rect getPaddle();
	void Render();
private:
	SDL_Renderer* m_Renderer;
	SDL_Rect paddle_Rect;
	int paddleWidth;
	int paddleHeight;
	int paddleVelocity;
};



#endif