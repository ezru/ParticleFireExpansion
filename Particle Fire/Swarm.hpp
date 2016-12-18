//
//  Swarm.hpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>
#include "Particle.hpp"

class Swarm {
    
public:
    const static int NPARTICLES = 5000;
    
public:
    Swarm();
    virtual ~Swarm();
    
    const Particle  *const getParticles() { return m_pParticle; }
    
private:
    
    Particle *m_pParticle;
    
};

#endif /* Swarm_hpp */
