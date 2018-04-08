#include "TimerTask.h"



TimerTask::TimerTask(std::function<void()> newFunc, float interval, float delay) {
	func = newFunc;
	this->interval = interval;
	this->delay = delay;

	if (interval > 0) {
		lastCallTime = 0;
	}
	else {
		lastCallTime = ofGetElapsedTimef();
	}
}

void TimerTask::call() {
	lastCallTime = ofGetElapsedTimef();
	func();
}