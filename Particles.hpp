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
    
private:
    double m_speed;
    double m_direction;
    
private:
    void init();
    
public:
    Particle();
    virtual ~Particle();
    void update(int interval);
};
} /* namespace Particle*/


#endif /* Particles_hpp */
