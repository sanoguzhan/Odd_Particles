//
//  crowd.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include "crowd.hpp"

namespace  particles{
Crowd::Crowd(): lastTime(0) {
    w_pParticles = new Particle[No_Particle];

}

Crowd::~Crowd() {
    delete [] w_pParticles;
}
void Crowd::update(int elapsed) {

    int interval = elapsed - lastTime;

    for (int i{0}; i < Crowd::No_Particle; ++i) {
        w_pParticles[i].update(interval);
    }

    lastTime = elapsed;
}

}
