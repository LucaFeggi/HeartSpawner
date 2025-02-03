#include "Window.hpp"

inline SDL_HitTestResult hitTestCallback(SDL_Window* window, const SDL_Point* point, void* data) {
	return SDL_HITTEST_DRAGGABLE;
}

void Window::init(std::string texturePath) {
	screenResolution = getScreenResolution();
	windowRect = getWindowRect();
	windowRect.w = defaultTextureSize * 3 / 2;
	windowRect.h = defaultTextureSize * 3 / 2;
	window = SDL_CreateWindow(nullptr, windowRect.x, windowRect.y, windowRect.w, windowRect.h, SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_BORDERLESS);
	SDL_SetWindowHitTest(window, hitTestCallback, nullptr);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	texture.init(renderer);
	texture.loadFromFile(texturePath);
	textureRect = { 0, 0, defaultTextureSize * 3 / 2, defaultTextureSize * 3 / 2 };
}

void Window::free() {
	texture.free();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

Vec2<int> Window::getScreenResolution() {
	SDL_Rect displayBounds;
	SDL_GetDisplayBounds(0, &displayBounds);
	Vec2<int> res{ displayBounds.w , displayBounds.h };
	return res;
}

SDL_Rect Window::getWindowRect() {
	Vec2<int> dim{ screenResolution.x / 3, screenResolution.y / 3 };
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distX(1, screenResolution.x - defaultTextureSize * 3 / 2);
	std::uniform_int_distribution<std::mt19937::result_type> distY(1, screenResolution.y - defaultTextureSize * 3);
	Vec2<int> pos = { (int)distX(rng), (int)distY(rng) };
	SDL_Rect rect = { pos.x, pos.y, dim.x, dim.y };
	return rect;
}

void Window::render() {
	SDL_RenderClear(renderer);
	texture.render(nullptr, &textureRect);
	SDL_RenderPresent(renderer);
}