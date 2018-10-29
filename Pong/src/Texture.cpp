#include "Texture.h"

Texture::Texture()
{
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

Texture::~Texture()
{
}