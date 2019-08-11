#include "Ball.h"

const std::string Ball::_ImageFileName = "./img/Ball.png";
const int Ball::_width = 8;
const int Ball::_height = 8;

Ball::Ball()
{
}


Ball::~Ball()
{
	delete _texture;
}

Ball::Ball(SDL_Renderer* &renderer, int windowWidth, int windowHeight, int yPos)
{
	_texture = new Texture();
	_texture->LoadImage(renderer, _ImageFileName);

	// TODO: set x and y positions
	_xpos = 31;
	_ypos = yPos;

	_texture->SetRectangle(_xpos, _ypos, _width, _height, true);
}

bool Ball::LoadImage(SDL_Renderer* &renderer, std::string file)
{
	_texture = new Texture();
	return _texture->LoadImage(renderer, file);
}

void Ball::MoveBall(Uint32 deltaTicks)
{

}

void Ball::UpdateRectanglePos()
{
	_texture->GetRectangle()->x = _xpos;
	_texture->GetRectangle()->y = _ypos;
}