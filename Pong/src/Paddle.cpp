#include "Paddle.h"

Paddle::Paddle()
{
}


Paddle::~Paddle()
{
}

void Paddle::setPlayerControlled(uint8_t p)
{
	m_player = p;
	m_bIsComputerControlled = false;
}