#pragma once

#include "ofMain.h"

class TimerTask {
public:
	TimerTask(std::function<void()>, float interval);

	//void(*function)();
	std::function<void()> func;

	void call();

	float interval;
	float lastCallTime;
};

