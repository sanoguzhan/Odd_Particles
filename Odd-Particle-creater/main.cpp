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
using namespace std;

int main() {
    
//    int height{720};
    srand(time(NULL));
    
    Window window;
    if(window.init() == false)
        std::cout << "SDL initializing Error" << std::endl;
    
    Crowd crowd;
    
    while(1){
        
        size_t elapsed = SDL_GetTicks();
        crowd.update(elapsed);
        
        double green = 128 * (1 + sin(elapsed * 0.001));
        green > 255 ? green = 255 : green ;
        double red = 128 * (1 + sin(elapsed * 0.002));
        red > 255 ? red = 255 : red ;
        double blue = 128 * (1 + sin(elapsed * 0.003));
        blue > 255 ? blue = 255 : blue ;

        const Particle * const pParticles = crowd.getParticle();
        
        for(int i{0}; i < Crowd::No_Particle; i++){
            Particle particle = pParticles[i];
            
            int x = (particle.m_x + 1) * 320;
            int y = particle.m_y *640 + 180;
            window.Pixels(x,y,red,green,blue);
        }
            
        window.boxBlur();
        window.update();
        if(window.processEvents() == false)
           break;
    }

    window.close();

    return 0;
}


