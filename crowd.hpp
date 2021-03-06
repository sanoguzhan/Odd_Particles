//
//  crowd.hpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#ifndef crowd_hpp
#define crowd_hpp

#include "Particles.hpp"
#include <stdio.h>

namespace particles{

class Crowd{
public:
    const static int No_Particle{1000000};
    
private:
    Particle * w_pParticles;
    int lastTime;

public:
    Crowd();
    virtual ~Crowd();
    void update(int elapsed);
    
    const Particle * const getParticle() {
        return w_pParticles;
        
    };
};
}

#endif /* crowd_hpp */
