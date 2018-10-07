#include "Paddle.h"

const std::string Paddle::sImageFileName = "./img/Paddle.png";

Paddle::Paddle()
{
	_player = 1;
	_bIsComputerControlled = false;
}

Paddle::Paddle(uint8_t player, bool icc)
{
	_player = player;
	_bIsComputerControlled = icc;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = 10;
	rectangle.h = 50;
}

void Paddle::setPlayerControlled(bool b, uint8_t p)
{
	_player = p;
	_bIsComputerControlled = b;
}

bool Paddle::LoadDefaultImage(SDL_Renderer* &renderer)
{
	return LoadImage(renderer, sImageFileName);
}

bool Paddle::LoadImage(SDL_Renderer* &renderer, std::string file)
{
	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* returnImage = nullptr;

	// load image from file
	loadedImage = IMG_Load(file.c_str());

	if (loadedImage == nullptr)
	{
		_image = nullptr;
		return false;
	}

	returnImage = SDL_CreateTextureFromSurface(renderer, loadedImage);
	SDL_FreeSurface(loadedImage);
	_image = returnImage;
	return true;
}

Paddle::~Paddle()
{
	SDL_DestroyTexture(_image);
	_image = nullptr;
}