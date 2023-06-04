#include <iostream>
#include <SDL.h>
#include <vector>
#include "ball.h"
#include "block.h"
#include "g.h"
#include "paddle.h"


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Breakout Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //instance
    Ball ball(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    Block block(renderer);
    Paddle paddle(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);



    std::vector<Block*> blocks;

    int startX = 10;
    int startY = 40;

    for (int i = 1; i <= TOTAL_BLOCKS; i++) {
        if (i == 11) {
            startY += 55;
            startX = 10;
        }
        Block* newBlock = new Block(renderer); //setRect to getRect 
        newBlock->setPosition(startX, startY);
        blocks.push_back(newBlock);
        startX += 75;
    }

    //game loop
    bool quit = false;
    SDL_Event event;
      while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Update and render the ball
        if (ball.ballTouchtheBottom()) {
            std::cout << "You Lose !" << std::endl;
            break;
        }
        float deltaTime = 0.016f;  // Assuming a fixed time step of 16ms (60 FPS)
        ball.Update(deltaTime);
        ball.Render();
        if (ball.CheckCollisionWithPaddle(paddle.getPaddle())) {
            ball.ReverseYVel();
        }
        


        //update and render the blocks
        for (int i = 0; i < TOTAL_BLOCKS; i++) {
            Block* blockPtr = blocks[i];
            if (blockPtr->getDestroyed() == true)continue; // *render naosu
            if (ball.CheckCollisionWithBlock(blockPtr->getBlock())) {
                blockPtr->erase();
                ball.ReverseYVel();
            }
        }


        //check out you win or not
        bool allDestroyed = true;
        for (int i = 0; i < TOTAL_BLOCKS; i++) {
            Block* blockPtr = blocks[i];
            if (blockPtr->getDestroyed())continue;
            else {
                blockPtr->Render();
                allDestroyed = false;
            }
        }

        if (allDestroyed) {
            std::cout << "You Win!" << std::endl;
            break;
        }

        //update the paddle
        paddle.handleInput();
        paddle.Render();
        // Present the renderer to display the rendered frame
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
