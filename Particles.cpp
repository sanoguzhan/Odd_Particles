//
//  Particles.cpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#include "Particles.hpp"
#include <stdlib.h>
#include <math.h>
namespace particles {
Particle::Particle() :
        m_x(0), m_y(0) {

    init();
}

void Particle::init() {
    m_x = 0;
    m_y = 0;
    m_direction = (0.9 * M_PI * rand()) / RAND_MAX;
    m_speed = (0.04 * rand()) / RAND_MAX;

    m_speed *= m_speed;
}

void Particle::update(int interval) {

    m_direction += interval *0.01;

    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed * interval;
    m_y += yspeed * interval;

    if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
        init();
    }

    if (rand() < RAND_MAX / 100) {
        init();
    }
}
Particle:: ~Particle(){
    
}
}
