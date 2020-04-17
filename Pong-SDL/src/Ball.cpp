#include "Ball.h"

const std::string Ball::_ImageFileName = "./img/Ball.png";
const int Ball::_width = 8;
const int Ball::_height = 8;
const float Ball::_movementSpeed = 0.1f;

Ball::Ball()
{
	_texture = new Texture();
	_xpos = 0;
	_ypos = 0;
	_xMovement = 0;
	_yMovement = 0;
}


Ball::~Ball()
{
	delete _texture;
}

Ball::Ball(SDL_Renderer* &renderer, int windowWidth, int windowHeight, int yPos)
{
	_texture = new Texture();
	_texture->LoadImage(renderer, _ImageFileName);

	// all this currently assumes player 1 starts the ball
	_xpos = 31;
	_ypos = yPos;
	_xMovement = 1;
	_yMovement = -1;	// probably can leave this as -1 always even if player 2 starts the game. Or make it random?

	_texture->SetRectangle(_xpos, _ypos, _width, _height, true);
}

bool Ball::LoadImage(SDL_Renderer* &renderer, std::string file)
{
	_texture = new Texture();
	return _texture->LoadImage(renderer, file);
}

void Ball::MoveBall(Uint32 deltaTicks)
{
	_xpos += (int) (_xMovement * _movementSpeed * deltaTicks);
	_ypos += (int) (_yMovement * _movementSpeed * deltaTicks);

	UpdateRectanglePos();
}

void Ball::UpdateRectanglePos()
{
	_texture->GetRectangle()->x = _xpos;
	_texture->GetRectangle()->y = _ypos;
}