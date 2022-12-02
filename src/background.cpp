#include "../headers/background.h"
#include "iostream"


Background::Background(const Window &window): Window(window) {
    //Initializing all of the rectangles to 0
    _groundRect = {0,0,0,0};
    _cloudsRect = {0,0,0,0};
    _skyRect = {0,0,0,0};
    

    //Loading the textures with their image
    _skyTexture = loadTexture("res/Sky.jpg");
    _groundTexture =  loadTexture("res/Ground.jpg");
    _cloudsTexture = loadTexture("res/Clouds.jpg");
}


//Destructor have to add Destory SDL Image
Background::~Background() {
    SDL_DestroyTexture(_skyTexture);
    SDL_DestroyTexture(_groundTexture);
    SDL_DestroyTexture(_cloudsTexture);
}

//Loading textures of images
SDL_Texture* Background::loadTexture(const char* filePath) {
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(_renderer, filePath);

    if (texture == NULL) {
        std::cout << "img couldn't load from file path: " << filePath << "Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Background::renderGround(int scroll) {
    while(scroll < 1100) {
        _groundRect = {scroll, 472, 128, 128};
        renderBackground(_groundRect, _groundTexture);
        scroll = scroll + 128;
    }
}

void Background::renderClouds(int scroll) {

    while(scroll < 1100) {
        _cloudsRect = {scroll, 0, 128, 128};
        renderBackground(_cloudsRect, _cloudsTexture);
        scroll = scroll + 128;
    }
}

void Background::renderSky(int scroll) {
    while(scroll < 1100) {
        _skyRect = {scroll, 128, 128, 600};
        renderBackground(_skyRect, _skyTexture);
        scroll = scroll + 128;
    }
}

void Background::draw(int scroll) {
    //Order matters so sky has to be first to make it blue then clouds added on top then ground
    renderSky(scroll);
    renderClouds(scroll);
    renderGround(scroll);
}

void Background::renderBackground(SDL_Rect rec, SDL_Texture* text) {
	if( movement != nullptr ) {
		rec.w = movement->w;
		rec.h = movement->h;
	}

	//Render to screen
	SDL_RenderCopyEx(_renderer, text, movement, &rec, 0.0, nullptr, SDL_FLIP_NONE);
}

