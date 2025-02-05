#ifndef HEARTSPAWNER_SRC_HEADERS_TEXTURE_HPP
#define HEARTSPAWNER_SRC_HEADERS_TEXTURE_HPP

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

class Texture {
public:
	void init(SDL_Renderer* renderer);
	void free();
	bool loadFromFile(std::string Path);
	bool loadFromRenderedText(std::string TextureText, SDL_Color TextColor, TTF_Font* Font);
	void setColor(SDL_Color Color);
	void setBlendMode(SDL_BlendMode Blending);
	void setAlpha(uint8_t Alpha);
	void render(SDL_Rect* Source = nullptr, SDL_Rect* Destination = nullptr);
	int getWidth();
	int getHeight();
private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	int w;
	int h;
};

#endif
