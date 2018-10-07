/*
Paddle class
*/

#include <stdint.h>

#pragma once
class Paddle
{
public:
	Paddle();
	~Paddle();
	inline void setComputerControlled() { m_bIsComputerControlled = true; }
	void setPlayerControlled(uint8_t p);

private:
	uint8_t m_player;	// player 1 or 2
	bool m_bIsComputerControlled;	// is the computer controlling this paddle
};

