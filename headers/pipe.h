#include "iostream"
#include "SDL.h"
#include "SDL_image.h"
#include "window.h"

#ifndef PIPE
#define PIPE

class Pipe : public Window { 
    public:
        Pipe(const Window &window);
        ~Pipe();
        void draw();
        void move();
        void pipeImage();
        SDL_Rect* getPos();
        SDL_Rect* getSkyPos();
        int getX();
        int getY();
        int getSkyX();
        int getSkyY();
        int getWidth();
        int getHeight();
        void setCollider(SDL_Rect* collider);
        void setSkyCollider(SDL_Rect* collider);

    private:
        // static const int DOT_WIDTH = 20;
        static const int PIPE_HEIGHT = 10;
        static const int VELOCITY = 1;
        int _mPosY;
        int _mPosX;
        int _skyPipeX;
        int _skyPipeY;
        int pipeWidth;
        int pipeHeight;
        SDL_Surface* _pipeSurface = nullptr;
        SDL_Texture* _pipeTexture = nullptr;
        SDL_Surface* _skyPipeSurface = nullptr;
        SDL_Texture* _skyPipeTexture = nullptr;
        SDL_Rect* _skyCollider = nullptr;
        SDL_Rect* _collider = nullptr;
};

#endif 
