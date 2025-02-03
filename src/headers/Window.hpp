#ifndef COMMUNICATINGWINDOWS_SRC_HEADERS_WINDOW_HPP
#define COMMUNICATINGWINDOWS_SRC_HEADERS_WINDOW_HPP

#include <SDL.h>
#include <string>
#include <random>
#include "Vec2.hpp"
#include "Texture.hpp"

constexpr int defaultTextureSize = 64;

class Window {
public:
	void init(std::string texturePath = "src/resource/textures/heart.png");
	void free();
	void render();
private:
	Vec2<int> getScreenResolution();
	SDL_Rect getWindowRect();
	Vec2<int> screenResolution;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect windowRect;
	Texture texture;
	SDL_Rect textureRect;
};

#endif