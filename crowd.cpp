//
//  crowd.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include "crowd.hpp"

namespace  particles {
Crowd:: Crowd(){
    w_pParticles = new Particle[No_Particle];
}
Crowd:: ~Crowd() {
    delete [] w_pParticles;
}
}
