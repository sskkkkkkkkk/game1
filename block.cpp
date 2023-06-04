#include "block.h"
#include <SDL.h>
#include "g.h"

Block::Block(SDL_Renderer* renderer)
    : m_Renderer(renderer),
    isDestroyed(false)
{
    m_Block.w = 70;
    m_Block.h = 35;
}

void Block::Update() {

};
void Block::Render() {
    SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255); // Red color for active block
    SDL_RenderFillRect(m_Renderer, &m_Block);
};


SDL_Rect Block::getBlock()  {
    return m_Block;
};

void Block::setPosition(int x, int y) {
    m_Block.x = x;
    m_Block.y = y;
};

int Block::getPositionX(SDL_Rect m_Block) {
    return m_Block.x;
};

int Block::getPositionY(SDL_Rect m_Block) {
    return m_Block.y;
};

bool Block::getDestroyed() {
    return isDestroyed;
};


void Block::erase() {
    isDestroyed = true;
};



