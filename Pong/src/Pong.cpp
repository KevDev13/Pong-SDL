/*
Pong clone.
*/

#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "Paddle.h"

constexpr int SCREEN_HEIGHT = 480;
constexpr int SCREEN_WIDTH = 640;
constexpr int MAX_FPS = 60;	// maximum FPS
constexpr int MAX_FPS_TICKS = 1000 / MAX_FPS;	// max FPS in ticks

bool init(SDL_Window* &window, SDL_Renderer* &renderer);
void cleanup(SDL_Window* &window, SDL_Renderer* &renderer);

enum State
{
	TitleScreen,

};

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

	Paddle* player1 = new Paddle(renderer, 1, SCREEN_WIDTH, SCREEN_HEIGHT);	// paddle for player 1
	Paddle* player2 = new Paddle(renderer, 2, SCREEN_WIDTH, SCREEN_HEIGHT);	// paddle for player 2

	// setup initial ticks for delta time calculations
	Uint32 currentTicks = SDL_GetTicks();
	Uint32 previousTicks = SDL_GetTicks();
	
	/* MAIN LOOP */
	while (!quit)
	{
		// calculate delta time since last frame
		currentTicks = SDL_GetTicks() - previousTicks;
		previousTicks = SDL_GetTicks();

		// prevent a tick of 0; since FPS is capped, may be able to remove this eventually
		if (currentTicks == 0)
		{
			SDL_Delay(1);
			currentTicks = 1;
		}

		// poll for & handle SDL events
		while (SDL_PollEvent( &sdlEvent ) != 0)
		{
			if(sdlEvent.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (sdlEvent.type == SDL_KEYDOWN)
			{
				// handle keyboard input... probably
			}
		}

		// get keyboard states and handle paddle movement
		const Uint8* keyStates = SDL_GetKeyboardState(nullptr);

		// player 1 movement - move if only 1 key is pressed, prevents movement from both keys
		if (keyStates[SDL_SCANCODE_W] && !keyStates[SDL_SCANCODE_S])
		{
			player1->MoveUp(currentTicks);
		}
		else if (keyStates[SDL_SCANCODE_S] && !keyStates[SDL_SCANCODE_W])
		{
			player1->MoveDown(currentTicks, SCREEN_HEIGHT);
		}

		// player 2 movement - move if only 1 key is pressed, prevents movement from both keys
		if (keyStates[SDL_SCANCODE_UP] && !keyStates[SDL_SCANCODE_DOWN])
		{
			player2->MoveUp(currentTicks);
		}
		else if (keyStates[SDL_SCANCODE_DOWN] && !keyStates[SDL_SCANCODE_UP])
		{
			player2->MoveDown(currentTicks, SCREEN_HEIGHT);
		}

		// clear then update the screen
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, player1->GetImage(), nullptr, player1->GetRectangle());
		SDL_RenderCopy(renderer, player2->GetImage(), nullptr, player2->GetRectangle());
		SDL_RenderPresent(renderer);

		// cap frame rate
		if (currentTicks < MAX_FPS_TICKS)
		{
			SDL_Delay(MAX_FPS_TICKS - currentTicks);
		}

		//std::cout << currentTicks << std::endl;
	}

	/* Cleanup */
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