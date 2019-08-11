#include "Ball.h"

const std::string Ball::_ImageFileName = "./img/Balls.png";
const int Ball::_width = 8;
const int Ball::_height = 8;

Ball::Ball()
{
}


Ball::~Ball()
{
	delete _texture;
}

Ball::Ball(SDL_Renderer* &renderer, uint8_t player, int windowWidth, int windowHeight)
{
	_texture = new Texture();
	_texture->LoadImage(renderer, _ImageFileName);

	// TODO: set x and y positions

	_texture->SetRectangle(_xpos, _ypos, _width, _height, true);
}

bool Ball::LoadImage(SDL_Renderer* &renderer, std::string file)
{
	_texture = new Texture();
	return _texture->LoadImage(renderer, file);
}

void Ball::UpdateRectanglePos()
{
	_texture->GetRectangle()->x = _xpos;
	_texture->GetRectangle()->y = _ypos;
}