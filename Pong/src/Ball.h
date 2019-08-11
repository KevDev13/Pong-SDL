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

	bool LoadImage(SDL_Renderer* &renderer, std::string file);

private:
	Texture* _texture;
};

