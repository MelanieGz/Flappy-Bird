#include "../headers/bird.h"
#include "iostream"

Bird::Bird(const Window &window) :
Window(window) {
    //Initalize position
    _mPosY = 200;
    _mPosX = 10;

    //Initialize the velocity
    _mVelY = 0;
    _mVelX = 0;

    //Initizlize collider
    SDL_Rect birdCollider = {_mPosX, _mPosY, 70, 70};
    _collider = &birdCollider;

    //Create bird image
    birdImage();
    SDL_FillRect(_birdSurface, _collider, SDL_MapRGB(_birdSurface->format,255,0,0));
}

void Bird::setCollider(SDL_Rect* collider) {
    _collider = collider;
}

SDL_Rect* Bird::getPos() {
    return _collider;
}

int Bird::getPosX() {
    return _mPosX;
}

int Bird::getPosY() {
    return _mPosY;
}

Bird::~Bird() {
    SDL_DestroyTexture(_birdTexture);
    SDL_FreeSurface(_birdSurface);
}
    //Create image of bird
void Bird::birdImage() {
    _birdSurface = IMG_Load("res/FlappyBird.jpg");

    if(!_birdSurface) {
        std::cout << "Failed to create bird surface." << std::endl;
    }

    _birdTexture = SDL_CreateTextureFromSurface(_renderer, _birdSurface);

    if (!_birdTexture) {
        std::cout << "Failed to create bird texture." << std::endl;
    }
}

//Check for user input
void Bird::pollEvents(SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
        case SDLK_UP: 
            // Move up
            _mPosY -= 25;
            _collider->y -= 25;
            break;
        case SDLK_DOWN:
            // Move down
            _mPosY += 25;
            _collider->y += 25;
            break;
        }
    } 
}

//Draws image of bird onto screen
void Bird::draw() {
    SDL_Rect rect = {_mPosX, _mPosY, 70, 70};
    SDL_RenderCopy(_renderer, _birdTexture, nullptr, &rect);
}

//Bird movements
void Bird::move() {
    //Move bird up or down


    //If bird too far up, fix
    if((_mPosY < 0) ||(_mPosY + BIRD_HEIGHT > 650)) {
        //Move back
        _mPosY -= _mVelY;
    }
}


