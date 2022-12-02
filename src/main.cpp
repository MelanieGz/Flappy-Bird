#include "iostream"
#include "vector"
#include "../headers/bird.h"
#include "../headers/pipe.h"
#include "../headers/window.h"
#include "../headers/background.h"
#include <chrono>
using namespace std::chrono;

void pollEvents(Window &window, Bird &bird)
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        bird.pollEvents(event);
        window.pollEvents(event);
    }
}

int main(int argc, char* argv[]) {
    int screenWidth = 1024;
    int screenHeight = 600;
    auto start = high_resolution_clock::now();
    Window window("Flappy Bird", screenWidth, screenHeight);
    bool pipe0Spawned = false;
    bool pipe1Spawned = false;
    bool pipe2Spawned = false;
    bool pipe3Spawned = false;
    bool pipe4Spawned = false;
    bool pipeCollision = false;
    int withOffset = 175;
    int yOffset = -45;
    int yGroundOffset = 30;
    int scrollOffset = 0;
    int pipeSpawnDistance = 700;
    SDL_Rect skyCollider = {0,-30,1024,5};
    SDL_Rect groundCollider = {0,490,1024,5};
    SDL_Rect birdCollider = {10,200,70,70};
    Bird bird(window);
    Pipe pipe(window);
    std::vector<Pipe*> pipes;

    // Game game(window);
    Background background(window);
    bird.setCollider(&birdCollider);
    
    while(!window.isClosed() && !pipeCollision) {
        SDL_Rect pipeCollider = {pipe.getX() + 100, pipe.getY() + yGroundOffset, pipe.getWidth() - withOffset, pipe.getHeight()};
        pipe.setCollider(&pipeCollider);
        SDL_Rect skyPipeCollider = {pipe.getSkyX() + 100, pipe.getSkyY() + yOffset, pipe.getWidth() - withOffset, pipe.getHeight()};
        pipe.setSkyCollider(&skyPipeCollider);
        
        pollEvents(window, bird);
        --scrollOffset;
        if (scrollOffset < -1024)
        {
            scrollOffset = 0;
        }

        // Clear screen
        SDL_RenderClear(window.getWindowRenderer());

        // Render background
        background.draw(scrollOffset);
        bird.draw();
        pipe.draw();
        pipe.move();
        
        if (pipe.getX() == pipeSpawnDistance || pipe0Spawned) {
            if (!pipe0Spawned) {
                pipes.push_back(new Pipe(window));
            }
            SDL_Rect pipeColliders0 = {pipes.at(0)->getX() + 100, pipes.at(0)->getY() + yGroundOffset, pipes.at(0)->getWidth() - withOffset, pipes.at(0)->getHeight()};
            pipes.at(0)->setCollider(&pipeColliders0);
            SDL_Rect skyPipeColliders0 = {pipes.at(0)->getSkyX() + 100, pipes.at(0)->getSkyY() + yOffset, pipes.at(0)->getWidth() - withOffset, pipes.at(0)->getHeight()};
            pipes.at(0)->setSkyCollider(&skyPipeColliders0);
            pipes.at(0)->draw();
            pipes.at(0)->move(); 
            pipe0Spawned = true;
        }
        if (pipe0Spawned && (pipes.at(0)->getX() == pipeSpawnDistance || pipe1Spawned)) {
            if (!pipe1Spawned) {
                pipes.push_back(new Pipe(window));
            }
            SDL_Rect pipeColliders1 = {pipes.at(1)->getX() + 100, pipes.at(1)->getY() + yGroundOffset, pipes.at(1)->getWidth() - withOffset, pipes.at(1)->getHeight()};
            pipes.at(1)->setCollider(&pipeColliders1);
            SDL_Rect skyPipeColliders1 = {pipes.at(1)->getSkyX() + 100, pipes.at(1)->getSkyY() + yOffset, pipes.at(1)->getWidth() - withOffset, pipes.at(1)->getHeight()};
            pipes.at(1)->setSkyCollider(&skyPipeColliders1);
            pipes.at(1)->draw();
            pipes.at(1)->move();
            pipe1Spawned = true;;
        }
        if (pipe1Spawned && (pipes.at(1)->getX() == pipeSpawnDistance || pipe2Spawned)) {
            if (!pipe2Spawned) {
                pipes.push_back(new Pipe(window));
            }
            SDL_Rect pipeColliders2 = {pipes.at(2)->getX() + 100, pipes.at(2)->getY() + yGroundOffset, pipes.at(2)->getWidth() - withOffset, pipes.at(2)->getHeight()};
            pipes.at(2)->setCollider(&pipeColliders2);
            SDL_Rect skyPipeColliders2 = {pipes.at(2)->getSkyX() + 100, pipes.at(2)->getSkyY() + yOffset, pipes.at(2)->getWidth() - withOffset, pipes.at(2)->getHeight()};
            pipes.at(2)->setSkyCollider(&skyPipeColliders2);
            pipes.at(2)->draw();
            pipes.at(2)->move();
            pipe2Spawned = true;;
        }
        if (pipe2Spawned && (pipes.at(2)->getX() == pipeSpawnDistance || pipe3Spawned)) {
            if (!pipe3Spawned) {
                pipes.push_back(new Pipe(window));
            }
            SDL_Rect pipeColliders3 = {pipes.at(3)->getX() + 100, pipes.at(3)->getY() + yGroundOffset, pipes.at(3)->getWidth() - withOffset, pipes.at(3)->getHeight()};
            pipes.at(3)->setCollider(&pipeColliders3);
            SDL_Rect skyPipeColliders3 = {pipes.at(3)->getSkyX() + 100, pipes.at(3)->getSkyY() + yOffset, pipes.at(3)->getWidth() - withOffset, pipes.at(3)->getHeight()};
            pipes.at(3)->setSkyCollider(&skyPipeColliders3);
            pipes.at(3)->draw();
            pipes.at(3)->move();
            pipe3Spawned = true;;
        }
        if (pipe3Spawned && (pipes.at(3)->getX() == pipeSpawnDistance || pipe4Spawned)) {
            if (!pipe4Spawned) {
                pipes.push_back(new Pipe(window));
            }
            SDL_Rect pipeColliders4 = {pipes.at(4)->getX() + 100, pipes.at(4)->getY() + yGroundOffset, pipes.at(4)->getWidth() - withOffset, pipes.at(4)->getHeight()};
            pipes.at(4)->setCollider(&pipeColliders4);
            SDL_Rect skyPipeColliders4 = {pipes.at(4)->getSkyX() + 100, pipes.at(4)->getSkyY() + yOffset, pipes.at(4)->getWidth() - withOffset, pipes.at(4)->getHeight()};
            pipes.at(4)->setSkyCollider(&skyPipeColliders4);
            pipes.at(4)->draw();
            pipes.at(4)->move();
            pipe4Spawned = true;;
        }

        window.clear();
        if (SDL_HasIntersection(bird.getPos(), &groundCollider) 
        || SDL_HasIntersection(bird.getPos(), &skyCollider) 
        || SDL_HasIntersection(bird.getPos(), pipe.getPos())
        || SDL_HasIntersection(bird.getPos(), pipe.getSkyPos())
        || (pipe0Spawned && (SDL_HasIntersection(bird.getPos(), pipes.at(0)->getPos()) || SDL_HasIntersection(bird.getPos(), pipes.at(0)->getSkyPos())))
        || (pipe1Spawned && (SDL_HasIntersection(bird.getPos(), pipes.at(1)->getPos()) || SDL_HasIntersection(bird.getPos(), pipes.at(1)->getSkyPos())))
        || (pipe2Spawned && (SDL_HasIntersection(bird.getPos(), pipes.at(2)->getPos()) || SDL_HasIntersection(bird.getPos(), pipes.at(2)->getSkyPos())))
        || (pipe3Spawned && (SDL_HasIntersection(bird.getPos(), pipes.at(3)->getPos()) || SDL_HasIntersection(bird.getPos(), pipes.at(3)->getSkyPos())))
        || (pipe4Spawned && (SDL_HasIntersection(bird.getPos(), pipes.at(4)->getPos()) || SDL_HasIntersection(bird.getPos(), pipes.at(4)->getSkyPos())))) {

            // run gameover method
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            std::cout << "game over" << std::endl;
            std::cout << "Score: " << duration.count() << std::endl;
            break;
        }
    }
    return 0;
}
