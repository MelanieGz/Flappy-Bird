#include "../headers/pipe.h"
#include "iostream"
#include "cstdlib"

Pipe::Pipe(const Window &window) :
Window(window) {
    //Initalize position
    int randomNum = (rand() % 241) + 200;
    _mPosY = randomNum;
    _mPosX = 900;

    _skyPipeY = randomNum - 465;
    _skyPipeX = 900;
    
    pipeWidth = 200;
    pipeHeight = 400;

    //Initizlize collider
    SDL_Rect pipeCollider = {_mPosX, _mPosY, pipeWidth, pipeHeight};
    _collider = &pipeCollider;

    SDL_Rect skyPipeCollider = {_skyPipeX, _skyPipeY, pipeWidth, pipeHeight};
    _skyCollider = &skyPipeCollider;

    //Create Pipe image
    pipeImage();
}

Pipe::~Pipe() {
    SDL_DestroyTexture(_pipeTexture);
    SDL_FreeSurface(_pipeSurface);
    SDL_DestroyTexture(_skyPipeTexture);
    SDL_FreeSurface(_skyPipeSurface);
}

int Pipe::getSkyX() {
    return _skyPipeX;
}

int Pipe::getSkyY(){
    return _skyPipeY;
}

int Pipe::getX() {
    return _mPosX;
}

int Pipe::getY() {
    return _mPosY;
}

int Pipe::getWidth() {
    return pipeWidth;
}

int Pipe::getHeight() {
    return pipeHeight;
}

void Pipe::setCollider(SDL_Rect* collider) {
    _collider = collider;
}

 void Pipe::setSkyCollider(SDL_Rect* collider) {
    _skyCollider = collider;
 }

//Create image of pipe
void Pipe::pipeImage() {
    _pipeSurface = IMG_Load("res/New_pipe.jpg");

    if(!_pipeSurface) {
        std::cout << "Failed to create pipe surface." << std::endl;
    }

    _pipeTexture = SDL_CreateTextureFromSurface(_renderer, _pipeSurface);

    if (!_pipeTexture) {
        std::cout << "Failed to create pipe texture." << std::endl;
    }

    _skyPipeSurface = IMG_Load("res/SkyPipe.jpg");
    _skyPipeTexture = SDL_CreateTextureFromSurface(_renderer, _skyPipeSurface);
}

//Draws image of pipe onto screen
void Pipe::draw() {
    SDL_Rect rect = {_mPosX, _mPosY, pipeWidth, pipeHeight};
    SDL_Rect skyRect = {_skyPipeX, _skyPipeY, pipeWidth, pipeHeight};
    SDL_RenderCopy(_renderer, _pipeTexture, nullptr, &rect);
    SDL_RenderCopy(_renderer, _skyPipeTexture, nullptr, &skyRect);
}

//Pipe movements
void Pipe::move() {
    //Move left up or right
    _mPosX-=2;
    _collider->x-=2;
    _skyPipeX-=2;
    _skyCollider->x-=2;

    if (_mPosX <= -200) {
        _mPosX = 1024;
        _collider->x = 1024;
        _skyPipeX = 1024;
        _skyCollider->x = 1024;
    }
}

SDL_Rect* Pipe::getPos() {
    return _collider;
}

SDL_Rect* Pipe::getSkyPos() {
    return _skyCollider;
}
