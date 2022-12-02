#include <string>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#ifndef WINDOW_H
#define WINDOW_H

class Window
{
public:
    Window(const char *title, int w, int h);
    ~Window();
    void pollEvents(SDL_Event &event);
    void clear();
    bool isClosed();
    SDL_Renderer *getWindowRenderer();
    const char *getTitle() { return _title; };
    const int getWidth() { return _width; };
    const int getHeight() { return _height; };
    bool getStatus() { return init(); }
protected:
    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;
    int _width = 800;
    int _height = 600;
    bool init();

private:
    const char *_title;
    bool _closed;
};

#endif