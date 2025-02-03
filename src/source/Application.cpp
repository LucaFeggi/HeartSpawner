#include "Application.hpp"


void Application::init() {
	SDL_InitSubSystem(SDL_INIT_EVERYTHING);
	quit = false;
	inputs.init();
	windowsManager.init();
}

void Application::free() {
	windowsManager.free();
	inputs.free();
	SDL_Quit();
}

void Application::run() {
	init();
	while (!quit) {
		quit = inputs.run();
		windowsManager.setQuit(quit);
	}
	free();
}