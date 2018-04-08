#include "Timer.h"
#include "Actor.h"


void sample() {
	cout << "Function got called" << endl;
}

Timer::Timer() {

}

Timer::~Timer() {
}

void Timer::update() {
	for (TimerTask* task : tasks) {
		// Repeating tasks
		if (task && task->interval > 0 && task->lastCallTime + task->interval <= ofGetElapsedTimef()) {
			task->call();
		}
		// One-time tasks
		else if (task && task->delay > 0 && task->lastCallTime + task->delay <= ofGetElapsedTimef()) {
			cout << "CALLING DELAYED TIMED FUNCTION" << endl;
			task->call();
			//task->delay = 0;
			//task->interval = 0;
			cout << "END OF LOOP LOOp" << endl;
		}
	}
}

TimerTask* Timer::createTask(std::function<void()> newFunction, float interval) {
	TimerTask* newTask = new TimerTask(newFunction, interval);
	tasks.push_back(newTask);

	return newTask;
}

TimerTask* Timer::addTask(TimerTask* newTask) {
	if (newTask) {
		tasks.push_back(newTask);
		return newTask;
	}

	return nullptr;
}

void Timer::removeTask(TimerTask* toRemove) {
	ptrdiff_t index = std::find(tasks.begin(), tasks.end(), toRemove) - tasks.begin();

	if (index < tasks.size()) {
		// Remove and delete if exists
		tasks.erase(tasks.begin() + index);
	}
}