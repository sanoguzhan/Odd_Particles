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
using namespace std;
using namespace particles;



int main() {

//    int height{720};
    Window window;
    if(window.init() == false)
        cout << "SDL initializing Error" << endl;
    
    while(1){
        for(int y{0}; y < 720; ++y){
            for(int x{0}; x < 1280; ++x)
                window.Pixels(x,y,128,0,255);
        }
        if(window.processEvents() == false)
           break;
    }

    window.update();
    window.close();
    return 0;
}


