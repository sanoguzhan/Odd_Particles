//
//  Particles.hpp
//  Odd-Particle-creater
//
//  Created by Oguzhan San on 23.10.19.
//  Copyright © 2019 Oguzhan San. All rights reserved.
//

#ifndef Particles_hpp
#define Particles_hpp


namespace particles{
struct Particle{
    double m_x;
    double m_y;
    
public:
    Particle();
    virtual ~Particle();
};
} /* namespace Particle*/


#endif /* Particles_hpp */
