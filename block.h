#ifndef BLOCK_H
#define BLOCK_H

#include <SDL.h>



class Block {
public:
	Block(SDL_Renderer* renderer);

	void Update();
	void Render();
	SDL_Rect getBlock();
	void setPosition(int x, int y);
	int getPositionX(SDL_Rect m_Block);
	int getPositionY(SDL_Rect m_Block);
	bool getDestroyed();
	void erase();
private:
	SDL_Rect m_Block;
	SDL_Renderer* m_Renderer;
	bool isDestroyed;

};

#endif