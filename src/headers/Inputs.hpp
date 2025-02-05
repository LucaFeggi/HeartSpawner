#ifndef HEARTSPAWNER_SRC_HEADERS_INPUTS_HPP
#define HEARTSPAWNER_SRC_HEADERS_INPUTS_HPP

#include <SDL.h>

class Inputs {
public:
	void init();
	void free();
	bool run();
private:
	void getInputs();
	void keyboard();
	bool quit;
	SDL_Event event;
};

#endif
