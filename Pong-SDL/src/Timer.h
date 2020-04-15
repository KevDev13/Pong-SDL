/*
	Timer class
*/

#pragma once

#include <SDL.h>

class Timer
{
public:
	Timer(bool start = false);

	bool Start();
	bool Stop();
	bool Pause();
	bool Reset();
	bool Restart();

	Uint32 GetTicks();

	inline bool IsRunning() { return _Started; }
	inline bool IsPaused() { return _Paused; }

protected:

	Uint32 _StartTicks;
	Uint32 _PausedTicks;
	
	bool _Paused;
	bool _Started;
};

