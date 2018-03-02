#pragma once

#include "ofMain.h"
#include "TimerTask.h"

class Actor;

// Timer
// Runs TimerTasks at their proper intervals
//
class Timer {
public:
	Timer();
	~Timer();

	void update();

	// Create a new task and add it to the timer
	TimerTask* createTask(std::function<void()>, float);

	// Add an existing task to the timer
	TimerTask* addTask(TimerTask*);

	// Remove a task from the timer
	void removeTask(TimerTask*);

private:
	// Tasks
	vector<TimerTask*> tasks;

};