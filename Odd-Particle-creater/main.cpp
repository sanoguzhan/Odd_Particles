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
using namespace std;
using namespace particles;



int main() {
    
//    int height{720};
    Window window;
    if(window.init() == false)
        cout << "SDL initializing Error" << endl;
    

    
    while(1){
        if(window.processEvents() == false)
           break;
    }
    window.close();
    return 0;
}


