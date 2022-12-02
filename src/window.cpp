#include "../headers/window.h"

// Window::Window(const char *title, int w, int h)
Window::Window(const char *title, int w, int h)
{
    _title = title;
    _width = w;
    _height = h;
    if (!init())
    {
        _closed = true;
    }
    else
    {
        _closed = false;
    }
}

Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

bool Window::isClosed()
{
    return _closed;
}

void Window::pollEvents(SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_QUIT:
        _closed = true;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            _closed = true;
            break;
        case SDLK_UP: 
            break;
        case SDLK_DOWN: 
            break;
        }
    default:
        break;
    }
}

bool Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Failed to initalize SDL." << std::endl;
        return false;
    }

    if (IMG_Init(IMG_INIT_JPG) != IMG_INIT_JPG)
    {
        std::cout << "Failed to initialize SDL Image." << std::endl;
        return false;
    }

    if (_width <= 0 || _height <= 0)
    {
        std::cout << "Failed to create window. Invalid dimensions." << std::endl;
        return false;
    }
    _window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

    if (_window == nullptr)
    {
        std::cout << "Failed to create window." << std::endl;
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (_renderer == nullptr)
    {
        std::cout << "Failed to create renderer." << std::endl;
        return false;
    }

    return true;
}

void Window::clear()
{
    SDL_RenderPresent(_renderer);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

SDL_Renderer *Window::getWindowRenderer()
{
    return _renderer;
}
