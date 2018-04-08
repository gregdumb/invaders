// Copyright Gregory Brisebois 4/8/2018

#pragma once

#include "ofMain.h"

// TimerTask
// Contains a function binding and an interval to call it at
// Must be used with a Timer
//
class TimerTask {
public:
	TimerTask(std::function<void()>, float interval, float delay=0);

	std::function<void()> func;

	void call();

	float delay;
	float interval;
	float lastCallTime;
};

