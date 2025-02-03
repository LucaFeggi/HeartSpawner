#include "Texture.hpp"

void Texture::init(SDL_Renderer* renderer) {
	w = 0;
	h = 0;
	texture = nullptr;
	this->renderer = renderer;
}

void Texture::free() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		renderer = nullptr;
		w = 0;
		h = 0;
	}
}

bool Texture::loadFromFile(std::string Path) {
	free();
	SDL_Texture* NewTexture = nullptr;
	SDL_Surface* LoadedSurface = IMG_Load(Path.c_str());
	if (LoadedSurface == nullptr) {
		printf("Unable to load image %s! SDL_image Error: %s\n", Path.c_str(), IMG_GetError());
	}
	else {
		SDL_SetColorKey(LoadedSurface, SDL_TRUE, SDL_MapRGB(LoadedSurface->format, 0, 0xFF, 0xFF));
		NewTexture = SDL_CreateTextureFromSurface(renderer, LoadedSurface);
		if (NewTexture == nullptr) {
			printf("Unable to create texture from %s! SDL Error: %s\n", Path.c_str(), SDL_GetError());
		}
		else {
			w = LoadedSurface->w;
			h = LoadedSurface->h;
		}
		SDL_FreeSurface(LoadedSurface);
	}
	texture = NewTexture;
	return texture != nullptr;
}

bool Texture::loadFromRenderedText(std::string TextureText, SDL_Color TextColor, TTF_Font *Font) {
	free();
	SDL_Surface* TextSurface = TTF_RenderText_Solid(Font, TextureText.c_str(), TextColor);
	if (TextSurface == nullptr) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else {
		texture = SDL_CreateTextureFromSurface(renderer, TextSurface);
		if (texture == nullptr) {
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else {
			w = TextSurface->w;
			h = TextSurface->h;
		}
		SDL_FreeSurface(TextSurface);
	}
	return texture != nullptr;
}

void Texture::setColor(SDL_Color Color) {
	SDL_SetTextureColorMod(texture, Color.r, Color.g, Color.b);
}

void Texture::setBlendMode(SDL_BlendMode Blending) {
	SDL_SetTextureBlendMode(texture, Blending);
}

void Texture::setAlpha(uint8_t Alpha) {
	SDL_SetTextureAlphaMod(texture, Alpha);
}

void Texture::render(SDL_Rect* Source, SDL_Rect* Destination) {
	SDL_RenderCopyEx(renderer, texture, Source, Destination, 0.0, nullptr, SDL_FLIP_NONE);
}

int Texture::getWidth() {
	return w;
}

int Texture::getHeight() {
	return h;
}