#include "Paddle.h"

const std::string Paddle::_ImageFileName = "./img/Paddle.png";
const int Paddle::_width = 10;
const int Paddle::_height = 50;
const int Paddle::_xpos = 20;

Paddle::Paddle()
{
	_player = 1;
	_bIsComputerControlled = false;
}

Paddle::Paddle(uint8_t player, int windowHeight, bool icc)
{
	_player = player;
	_bIsComputerControlled = icc;

	// set paddle to the middle of the window
	_ypos = (windowHeight / 2) - (_height / 2);

	_rectangle.x = _xpos;
	_rectangle.y = _ypos;
	_rectangle.w = _width;
	_rectangle.h = _height;
}

void Paddle::setPlayerControlled(bool b, uint8_t p)
{
	_player = p;
	_bIsComputerControlled = b;
}

bool Paddle::LoadDefaultImage(SDL_Renderer* &renderer)
{
	return LoadImage(renderer, _ImageFileName);
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