#ifndef HEARTSPAWNER_SRC_HEADERS_APPLICATION_HPP
#define HEARTSPAWNER_SRC_HEADERS_APPLICATION_HPP

#include <SDL.h>
#include "Inputs.hpp"
#include "WindowsManager.hpp"

class Application {
public:
	void init();
	void free();
	void run();
private:
	Inputs inputs;
	WindowsManager windowsManager;
	bool quit;
};
#endif
