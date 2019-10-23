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
#include "Windowcreater.hpp"
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "crowd.hpp"
using namespace particles;


int main() {
    
//    int height{720};
    srand(time(NULL));
    Window window;
    if(window.init() == false)
        std::cout << "SDL initializing Error" << std::endl;
    Crowd crowd;
    while(1){
        
        const particles::Particle * const pParticles = crowd.getParticle();
        for(size_t i{0}; Crowd::No_Particle; ++i){
            Particle particle = pParticles[i];
            int x = (particle.m_x + 1) * 640;
            int y = (particle.m_y + 1) * 360;
            window.Pixels(x,y,255,255,255);
        }
        /*
        size_t elapsed = SDL_GetTicks();
        double green = 128 * (1 + sin(elapsed * 0.0001));
        green > 255 ? green = 255 : green ;
        double red = 128 * (1 + sin(elapsed * 0.0002));
        red > 255 ? red = 255 : red ;
        double blue = 128 * (1 + sin(elapsed * 0.0003));
        blue > 255 ? blue = 255 : blue ;
        std::cout << green << std::endl;
        for(int y{0}; y < 720; ++y){
            for(int x{0}; x < 1280; ++x)
               window.Pixels(x,y,red,green,blue);
        }*/

        window.update();
        if(window.processEvents() == false)
           break;
    }

    window.close();
    return 0;
}


