/*
Paddle class
*/

#include <stdint.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

#pragma once
class Paddle
{
public:
	Paddle();
	Paddle(SDL_Renderer* &renderer, uint8_t player, int windowWidth, int windowHeight, bool icc = false);
	~Paddle();
	void setPlayerControlled(bool b, uint8_t p = 0);
	bool LoadImage(SDL_Renderer* &renderer, std::string file);
	void MoveUp(Uint32 deltaTicks);
	void MoveDown(Uint32 deltaTicks, const int screenHeight);

	inline uint8_t getPlayer() const { return _player; }
	inline bool isComputerControlled() const { return _bIsComputerControlled; }
	inline bool isPlayerControlled() const { return !_bIsComputerControlled; }
	inline SDL_Texture* GetImage() const { return _texture->GetImage(); }
	inline SDL_Rect* GetRectangle() const { return _texture->GetRectangle(); }

private:
	uint8_t _player;	// player 1 or 2
	bool _bIsComputerControlled;	// is the computer controlling this paddle?
	Texture* _texture;	// texture for paddle image
	int _ypos;	// current Y-position of the paddle
	int _xpos;	// current X-position of the paddle

	static const std::string _ImageFileName;
	static const int _width;
	static const int _height;
	static const float _movementSpeed;

	void UpdateRectanglePos();	// update rectangle with new position so it's drawn correctly
};

