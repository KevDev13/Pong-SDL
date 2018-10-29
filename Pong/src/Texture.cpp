#include "Texture.h"

Texture::Texture()
{
	_image = nullptr;
	_rectangle = new SDL_Rect();
}

bool Texture::LoadImage(SDL_Renderer* &renderer, std::string file)
{
	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* texture = nullptr;

	// load image from file
	loadedImage = IMG_Load(file.c_str());

	if (loadedImage == nullptr)
	{
		_image = nullptr;
		return false;
	}

	texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
	SDL_FreeSurface(loadedImage);
	_image = texture;
	return true;
}

void Texture::SetRectangle(int x, int y, int w, int h, bool createNewRect)
{
	if (createNewRect)
	{
		_rectangle = new SDL_Rect();
	}
	_rectangle->x = x;
	_rectangle->y = y;
	_rectangle->w = w;
	_rectangle->h = h;
}

Texture::~Texture()
{
	SDL_DestroyTexture(_image);
	_image = nullptr;
	_rectangle = nullptr;
}