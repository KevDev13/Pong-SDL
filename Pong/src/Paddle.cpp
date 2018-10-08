#include "Paddle.h"
#include <iostream>

const std::string Paddle::_ImageFileName = "./img/Paddle.png";
const int Paddle::_width = 10;
const int Paddle::_height = 50;

Paddle::Paddle()
{
	_player = 1;
	_bIsComputerControlled = false;
}

Paddle::Paddle(uint8_t player, int windowWidth, int windowHeight, bool icc)
{
	_player = player;
	_bIsComputerControlled = icc;

	// set X position based off of which player it is
	switch (player)
	{
	case 1:
		_xpos = 20;
		break;
	case 2:
		_xpos = windowWidth - 20 - _width;
		break;
	default:
		std::cout << "Error, paddle configured to something other than player 1 or 2" << std::endl;
	}

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

void Paddle::UpdateRectanglePos()
{
	_rectangle.x = _xpos;
	_rectangle.y = _ypos;
}

Paddle::~Paddle()
{
	SDL_DestroyTexture(_image);
	_image = nullptr;
}