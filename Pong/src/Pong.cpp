/*
Pong clone.
(c) 2018 Kilometer Games
kevin@kilometergames.com
*/

#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "Paddle.h"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

bool init(SDL_Window* &window, SDL_Renderer* &renderer);
void cleanup(SDL_Window* &window, SDL_Renderer* &renderer);

int main(int argc, char* args[])
{
	/* Initialization */

	SDL_Window* window = nullptr;	// SDL window
	SDL_Renderer* renderer = nullptr;	// SDL renderer attached to the window

	// initialize SDL and window, and if unable to do so, quit
	if (!init(window, renderer))
	{
		std::cout << "Error: unable to initialize SDL" << std::endl;
		return 1;
	}
	
	// value will be set to true when user wants to quit the game
	bool quit = false;

	SDL_Event sdlEvent;	// SDL event

	Paddle* player1 = new Paddle(1, false);	// paddle for player 1
	player1->LoadDefaultImage(renderer);
	
	/* MAIN LOOP */
	while (!quit)
	{
		// poll for & handle SDL events
		while (SDL_PollEvent( &sdlEvent ) != 0)
		{
			if(sdlEvent.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		// clear then update the screen
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, player1->GetImage(), nullptr, &player1->GetRectangle());
		SDL_RenderPresent(renderer);
	}

	/* Cleanup 
	*/
	cleanup(window, renderer);

	return 0;
}

bool init(SDL_Window* &window, SDL_Renderer* &renderer)
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}

	// create window and verify it was created
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		return false;
	}

	// create the window renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		return false;
	}

	// set background color to black
	if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) < 0)
	{
		return false;
	}

	// initialize SDL Image
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << IMG_GetError();
		return false;
	}
	return true;
}

void cleanup(SDL_Window* &window, SDL_Renderer* &renderer)
{
	// destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = nullptr;
	window = nullptr;

	// SDL cleanup
	IMG_Quit();
	SDL_Quit();
}