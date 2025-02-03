#include "WindowsManager.hpp"

void WindowsManager::init() {
	quit = false;
	for (int i = 0; i < totalWindows; i++) {
		windows[i].init();
	}
	runThread = std::thread(&WindowsManager::run, this);
}

void WindowsManager::free(){
	runThread.join();
	for (int i = 0; i < totalWindows; i++) {
		windows[i].free();
	}
}

void WindowsManager::run() {
	while(!quit){
		for (int i = 0; i < totalWindows; i++) {
			windows[i].render();
		}
	}
}

void WindowsManager::setQuit(bool quit) {
	this->quit = quit;
}