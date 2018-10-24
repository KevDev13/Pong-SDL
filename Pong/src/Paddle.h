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
	Paddle(uint8_t player, int windowWidth, int windowHeight, bool icc = false);
	~Paddle();
	void setPlayerControlled(bool b, uint8_t p = 0);
	bool LoadDefaultImage(SDL_Renderer* &renderer);
	bool LoadImage(SDL_Renderer* &renderer, std::string file);
	void MoveUp(Uint32 deltaTicks);
	void MoveDown(Uint32 deltaTicks);

	inline uint8_t getPlayer() const { return _player; }
	inline bool isComputerControlled() const { return _bIsComputerControlled; }
	inline bool isPlayerControlled() const { return !_bIsComputerControlled; }
	inline SDL_Texture* GetImage() const { return _image; }
	inline SDL_Rect GetRectangle() const { return _rectangle; }

private:
	uint8_t _player;	// player 1 or 2
	bool _bIsComputerControlled;	// is the computer controlling this paddle?
	SDL_Texture* _image;	// texture of the paddle
	SDL_Rect _rectangle;	// rectangle used to render the paddle
	int _ypos;	// current Y-position of the paddle
	int _xpos;	// current X-position of the paddle

	static const std::string _ImageFileName;
	static const int _width;
	static const int _height;

	void UpdateRectanglePos();	// update rectangle with new position so it's drawn correctly
};

