#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Texture
{
public:
	Texture();
	~Texture();

	bool LoadImage(SDL_Renderer* &renderer, std::string file);

	inline SDL_Texture* GetImage() const { return _image; }
	inline SDL_Rect* GetRectangle() const { return _rectangle; }

private:
	SDL_Texture* _image;
	SDL_Rect* _rectangle;
};

