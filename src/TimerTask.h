#pragma once

#include "ofMain.h"

// TimerTask
// Contains a function binding and an interval to call it at
// Must be used with a Timer
//
class TimerTask {
public:
	TimerTask(std::function<void()>, float interval);

	std::function<void()> func;

	void call();

	float interval;
	float lastCallTime;
};

