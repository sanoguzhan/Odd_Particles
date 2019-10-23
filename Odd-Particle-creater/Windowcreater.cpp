//
//  Window.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include "Windowcreater.hpp"

namespace  particles{
Window::Window() :
        w_window(nullptr),w_renderer(nullptr),w_texture(nullptr),w_buffer(nullptr){
}

bool particles::Window::init() {
    int width{1280};
    SDL_Init(SDL_INIT_VIDEO);
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        return false;
    }
    w_window = SDL_CreateWindow(
        "Odd Particle-Chaotic",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280,
        720,
        SDL_WINDOW_SHOWN
    );
    
    if(w_window == NULL){
        SDL_Quit();
        return false;
    }
    
    w_renderer = SDL_CreateRenderer(w_window, -1, SDL_RENDERER_PRESENTVSYNC);
    w_texture = SDL_CreateTexture(w_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 1280, 720);
    if(w_renderer == NULL){
        SDL_DestroyWindow(w_window);
        SDL_Quit();
    }
    if(w_texture ==NULL){
        SDL_DestroyTexture(w_texture);
        SDL_DestroyWindow(w_window);
        SDL_Quit();
    }
    Uint32 *buffer = new Uint32[1280*720];

    memset(buffer, 0, 1280*720*sizeof(Uint32));
    buffer[30000] = 0xFFFFFFFF;
    for(size_t i{0}; i < 1280*360 ; ++i)
        buffer[i] = 0x00FFFFFF;
    
    SDL_UpdateTexture(w_texture, NULL, buffer, width * sizeof(Uint32));
    SDL_RenderClear(w_renderer);
    SDL_RenderCopy(w_renderer, w_texture, NULL, NULL);
    SDL_RenderPresent(w_renderer);
    
    return true;
}
bool particles::Window::processEvents() {
    SDL_Event events;
    while(SDL_PollEvent(&events)){
        if(events.type == SDL_QUIT)
            return false;
        else
            continue;
    }
    return true;
}

void particles::Window::close(){
    delete [] w_buffer;
    SDL_DestroyRenderer(w_renderer);
    SDL_DestroyTexture(w_texture);
    SDL_DestroyWindow(w_window);
    SDL_Quit();
    
}
}
