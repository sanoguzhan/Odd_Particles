//
//  main.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 22.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        return 1;
    }
    cout << "dsad" << endl;
    SDL_Quit();
    return 0;
}
