//
//  Window.hpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#ifndef Windowcreater_hpp
#define Windowcreater_hpp
#include <SDL2/SDL.h>

namespace particles {
class Window {
private:
    SDL_Window *w_window;
    SDL_Renderer *w_renderer;
    SDL_Texture *w_texture;
    Uint32 *w_buffer1;
    Uint32 *w_buffer2;
public:
    Window();
    bool init();
    void update();
    void Pixels(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void updateRenderer();
    bool processEvents();
    void boxBlur();
    void close();
};
}

#endif /* Window_hpp */
