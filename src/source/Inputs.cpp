#include "Inputs.hpp"

void Inputs::init() {
	quit = false;
}

void Inputs::free() {}

void Inputs::getInputs() {
	while (SDL_PollEvent(&event)) {
		keyboard();
	}
}

void Inputs::keyboard() {
	if (event.key.state == SDL_PRESSED) {
		switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				quit = true;
				break;
			default:
				break;
		}
	}
}

bool Inputs::run() {
	getInputs();
	return quit;
}
