#ifndef COMMUNICATINGWINDOWS_SRC_HEADERS_WINDOWSMANAGER_HPP
#define COMMUNICATINGWINDOWS_SRC_HEADERS_WINDOWSMANAGER_HPP

#include <thread>
#include "Window.hpp"

constexpr int totalWindows = 103;

class WindowsManager {
public:
	void init();
	void free();
	void run();
	void setQuit(bool quit);
private:
	Window windows[totalWindows];
	std::thread runThread;
	bool quit;
};

#endif