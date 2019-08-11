#include "Ball.h"



Ball::Ball()
{
}


Ball::~Ball()
{
}

bool Ball::LoadImage(SDL_Renderer* &renderer, std::string file)
{
	_texture = new Texture();
	return _texture->LoadImage(renderer, file);
}