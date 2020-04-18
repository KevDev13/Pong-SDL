#include "Paddle.h"
#include <iostream>

const std::string Paddle::_ImageFileName = "./img/Paddle.png";
const int Paddle::_width = 10;
const int Paddle::_height = 50;
const float Paddle::_movementSpeed = 0.5;

Paddle::Paddle()
{
	_player = 1;
	_bIsComputerControlled = false;
	_texture = new Texture();
}

Paddle::Paddle(SDL_Renderer* &renderer, uint8_t player, bool icc)
{
	_player = player;
	_bIsComputerControlled = icc;
	_texture = new Texture();
	_texture->LoadImage(renderer, _ImageFileName);

	// set X position based off of which player it is
	switch (player)
	{
	case 1:
		_xpos = 20;
		break;
	case 2:
		_xpos = SCREEN_WIDTH - 20 - _width;
		break;
	default:
		std::cout << "Error, paddle configured to something other than player 1 or 2" << std::endl;
	}

	// set paddle to the middle of the window
	_ypos = (SCREEN_HEIGHT / 2) - (_height / 2);

	// create new rectangle
	_texture->SetRectangle(_xpos, _ypos, _width, _height, true);
}

void Paddle::setPlayerControlled(bool b, uint8_t p)
{
	_player = p;
	_bIsComputerControlled = b;
}

bool Paddle::LoadImage(SDL_Renderer* &renderer, std::string file)
{
	_texture = new Texture();
	return _texture->LoadImage(renderer, file);
}

void Paddle::MoveUp(Uint32 deltaTicks)
{
	_ypos -= (int) std::round(_movementSpeed * deltaTicks);
	// check to ensure paddle is not going outside screen
	if (_ypos < 0)
	{
		_ypos = 0;
	}
	UpdateRectanglePos();
}

void Paddle::MoveDown(Uint32 deltaTicks, const int screenHeight)
{
	_ypos += (int) std::round(_movementSpeed * deltaTicks);
	// check to ensure paddle is not going outside screen
	if (_ypos > (screenHeight - _height))
	{
		_ypos = screenHeight - _height;
	}
	UpdateRectanglePos();
}

void Paddle::UpdateRectanglePos()
{
	_texture->GetRectangle()->x = _xpos;
	_texture->GetRectangle()->y = _ypos;
}

Paddle::~Paddle()
{
	delete _texture;
}