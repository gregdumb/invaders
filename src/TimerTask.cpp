#include "TimerTask.h"



TimerTask::TimerTask(std::function<void()> newFunc, float interval) {
	func = newFunc;
	this->interval = interval;

	lastCallTime = 0;
}

void TimerTask::call() {
	lastCallTime = ofGetElapsedTimef();
	func();
}