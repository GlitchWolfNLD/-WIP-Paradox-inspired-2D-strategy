#include <Engine/game.hpp>
#include <Map/map.hpp>

using namespace Engine;

void Game::init()
{
    SDL_Init(SDL_INIT_VIDEO);

    this->window = SDL_CreateWindow("Strategy Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if (window != NULL)
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        map = new Map(this);
        map->init();

        isRunning = true;
    }
}

void Game::handleEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    
}

void Game::render()
{
    //Black background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    map->render();

    SDL_RenderPresent(renderer);
}