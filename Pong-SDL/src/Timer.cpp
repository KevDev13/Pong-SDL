#include "Timer.h"

Timer::Timer(bool start)
{
	_Started = start;
	if (_Started)
	{
		_StartTicks = SDL_GetTicks();
	}
	else
	{
		_StartTicks = 0;
	}

	_Paused = false;
	_PausedTicks = 0;
}

bool Timer::Start()
{
	// check to see if timer has already been started
	if (_Started)
	{
		if (_Paused)	// if timer is paused, then start timer up again
		{
			_Paused = false;
			_StartTicks = SDL_GetTicks() - _PausedTicks;
			_PausedTicks = 0;
			return true;
		}
		else
		{
			// if timer is started and not paused, return false since timer is already running
			return false;
		}

	}

	// if we got here, then timer hasn't been started yet so start it
	_Started = true;
	_Paused = false;

	_StartTicks = SDL_GetTicks();
	_PausedTicks = 0;

	return true;
}

bool Timer::Stop()
{
	// return false if timer has already been stopped
	if (!_Started)
	{
		return false;
	}

	_Started = false;
	_Paused = false;

	_StartTicks = 0;
	_PausedTicks = 0;

	return true;
}

bool Timer::Pause()
{
	// return false if already paused or timer hasn't been started yet
	if(_Paused || !_Started)
	{
		return false;
	}

	_Paused = true;
	_PausedTicks = SDL_GetTicks() - _StartTicks;

	return true;
}