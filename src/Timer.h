#pragma once

#include "ofMain.h"
#include "TimerTask.h"

class Actor;

class Timer {
public:
	Timer();
	~Timer();

	void update();

	TimerTask* createTask(std::function<void()>, float);
	TimerTask* addTask(TimerTask*);
	void removeTask(TimerTask*);

private:
	vector<TimerTask*> tasks;

	void timerTest();
};