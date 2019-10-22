//
//  main.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 22.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
using namespace std;



int main() {
    
    int height{720};
    int width{1280};
    SDL_Window *window = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL Failed! " << SDL_GetError() << endl;
        return 1;
    }
    window = SDL_CreateWindow(
        "Odd Particle-Chaotic",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280,
        720,
        SDL_WINDOW_SHOWN
    );
    
    if(window == NULL){
        SDL_Quit();
        return 2;
    }
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 1280, 720);
    if(renderer == NULL){
        cout << "Renderer Error" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    if(texture ==NULL){
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    Uint32 *buffer = new Uint32[1280*720];

    memset(buffer, 0xFF, 1280*720*sizeof(Uint32));
    SDL_UpdateTexture(texture, NULL, buffer, width * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
    bool exit{false};
    SDL_Event events;
    
    while(!exit){
        while(SDL_PollEvent(&events)){
            if(events.type == SDL_QUIT){
                exit = true;
            }
        }
    }
    
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}


