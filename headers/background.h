#include <iostream>
#include "window.h"
#include "SDL.h"
#include "SDL_image.h"

#ifndef BACKGROUND
#define BACKGROUND

class Background : public Window{

    private:
        SDL_Texture* _groundTexture = nullptr;
        SDL_Texture* _skyTexture = nullptr;
        SDL_Texture* _cloudsTexture = nullptr;

        SDL_Rect _groundRect;
        SDL_Rect _skyRect;
        SDL_Rect _cloudsRect;
        SDL_Rect* movement = nullptr;
        

    public:
        Background(const Window &window);
        ~Background();

        void draw(int scroll);
        void renderClouds(int scroll);
        void renderGround(int scroll);
        void renderSky(int scroll);
        
        void renderBackground(SDL_Rect rec, SDL_Texture* text);
        SDL_Texture* loadTexture(const char* filePath);
};

#endif