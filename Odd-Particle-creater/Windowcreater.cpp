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
        w_window(nullptr),w_renderer(nullptr),w_texture(nullptr),w_buffer1(nullptr),w_buffer2(nullptr){
}

bool Window::init() {
    
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
        return false;
    }
    if(w_texture ==NULL){
        SDL_DestroyTexture(w_texture);
        SDL_DestroyWindow(w_window);
        SDL_Quit();
        return false;
    }
    w_buffer1 = new Uint32[1280 * 720];
    w_buffer2 = new Uint32[1280 * 720];

    memset(w_buffer1, 0, 1280 * 720 * sizeof(Uint32));
    memset(w_buffer2, 0, 1280 * 720 * sizeof(Uint32));

    return true;
}
void Window::boxBlur() {
    
    Uint32 *temp = w_buffer1;
    w_buffer1 = w_buffer2;
    w_buffer2 = temp;

    for (int y = 0; y < 720; y++) {
        for (int x = 0; x < 1280; x++) {

            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;

            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    int currentX = x + col;
                    int currentY = y + row;

                    if (currentX >= 0 && currentX < 1280
                            && currentY >= 0 && currentY < 720) {
                        Uint32 color = w_buffer2[currentY * 720
                                + currentX];

                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                        
                    }
                }
            }

            Uint8 red = redTotal / 9;
            Uint8 green = greenTotal / 9;
            Uint8 blue = blueTotal / 9;

            Pixels(x, y, red, green, blue);
        }
    }

}

void Window::Pixels(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    if(x < 0 || x >= 1280 || y < 0 || y >= 720)
        return;
    int width{1280};
    
    Uint32 color{0};
    
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    w_buffer1[(y * width) + x] = color;
}

void Window::update(){
    int width{1280};
    SDL_UpdateTexture(w_texture, NULL, w_buffer1, width * sizeof(Uint32));
    SDL_RenderClear(w_renderer);
    SDL_RenderCopy(w_renderer, w_texture, NULL, NULL);
    SDL_RenderPresent(w_renderer);
}
void Window::updateRenderer() {
    SDL_RenderClear(w_renderer);
    SDL_RenderCopy(w_renderer, w_texture, nullptr, nullptr);
    SDL_RenderPresent(w_renderer);
}
bool Window::processEvents() {
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
    delete [] w_buffer1;
    delete [] w_buffer2;
    SDL_DestroyRenderer(w_renderer);
    SDL_DestroyTexture(w_texture);
    SDL_DestroyWindow(w_window);
    SDL_Quit();
    
}
}
