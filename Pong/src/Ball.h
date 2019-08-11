#pragma once

#include <stdint.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

class Ball
{
public:
	Ball();
	~Ball();
	Ball(SDL_Renderer* &renderer, uint8_t player, int windowWidth, int windowHeight);

	bool LoadImage(SDL_Renderer* &renderer, std::string file);

	inline SDL_Texture* GetImage() const { return _texture->GetImage(); }
	inline SDL_Rect* GetRectangle() const { return _texture->GetRectangle(); }

private:
	Texture* _texture;	// texture for ball image
	int _ypos;	// current Y-position of the ball
	int _xpos;	// current X-position of the ball

	static const std::string _ImageFileName;
	static const int _width;
	static const int _height;
	static const float _movementSpeed;

	void UpdateRectanglePos();	// update rectangle with new position so it's drawn correctly
};

