//
//  Shifting bit.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include "Shifting bit.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    unsigned char alpha{0xFF};
    unsigned char red{0x12};
    unsigned char green{0x34};
    unsigned char blue{0x56};
    
    unsigned int color = alpha;
    color += alpha;
    color <<= 8;
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    
    cout << setfill('0') << setw(8) << hex << endl;
    
    return 0;
}
