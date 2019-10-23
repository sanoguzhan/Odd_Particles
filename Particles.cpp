//
//  Particles.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include "Particles.hpp"
#include <stdlib.h>
namespace particles {
Particle::Particle(){
    m_x = 2.0 * rand()/RAND_MAX - 1;
    m_y = 2.0 * rand()/RAND_MAX - 1;
}
Particle:: ~Particle(){
    
}
}
