/*
Paddle class
*/

#include <stdint.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#pragma once
class Paddle
{
public:
	Paddle();
	Paddle(uint8_t player, bool isComputerControlled);
	~Paddle();
	void setPlayerControlled(bool b, uint8_t p = 0);
	bool LoadDefaultImage(SDL_Renderer* &renderer);
	bool LoadImage(SDL_Renderer* &renderer, std::string file);

	inline uint8_t getPlayer() const { return _player; }
	inline bool isComputerControlled() const { return _bIsComputerControlled; }
	inline bool isPlayerControlled() const { return !_bIsComputerControlled; }
	inline SDL_Texture* GetImage() const { return _image; }
	inline SDL_Rect GetRectangle() const { return rectangle; }

private:
	uint8_t _player;	// player 1 or 2
	bool _bIsComputerControlled;	// is the computer controlling this paddle?
	SDL_Texture* _image;
	SDL_Rect rectangle;

	static const std::string sImageFileName;
};

