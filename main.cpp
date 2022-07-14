#include <SDL.h>
#include <cstdio>
#include <utility>
#include <cmath>
#include <iostream>

int main(int argc, char **argv)
{
    int height = 300;
    int width = 400;
    SDL_Window *win = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    bool running = true;

    double a = 1;
    double b = 1;
    double c = 1;
    bool isDown = false;

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }

        SDL_Delay(80);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 24, 24, 24, 1);

        for (double x = 1; x < 1000;)
        {
            double y = a * x * x + b * x + c;
            // printf("%f \n", x);
            //  printf("%f \n", y);
            SDL_RenderDrawPointF(renderer, x, y);
            x += 0.2;
        }

        double *pointer = &a;

        if (floor(*pointer * 10) == 20)
        {
            isDown = true;
        }
        else if (floor(*pointer * 10) == 0)
        {
            isDown = false;
        }

        if (isDown)
        {
            *pointer -= 0.1;
        }
        else
        {
            *pointer += 0.1;
        }

        printf("%f \n", a);

        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 1;
}


