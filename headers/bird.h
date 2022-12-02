#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "window.h"

#ifndef BIRD
#define BIRD

class Bird : public Window { 
    public:
        Bird(const Window &window);
        ~Bird();
        void pollEvents(SDL_Event &event);
        void draw();
        void move();
        void birdImage();
        SDL_Rect* getPos();
        void setCollider(SDL_Rect* collider);
        int getPosX();
        int getPosY();

    private:
        // static const int DOT_WIDTH = 20;
        static const int BIRD_HEIGHT = 10;
        static const int VELOCITY = 1;
        int _mPosY;
        int _mVelY;
        int _mPosX;
        int _mVelX;
        SDL_Surface* _birdSurface = nullptr;
        SDL_Texture* _birdTexture = nullptr;
        SDL_Rect* _collider = nullptr;

};

#endif 
