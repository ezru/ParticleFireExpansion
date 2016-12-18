//
//  Particle.hpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include <stdlib.h>

struct Particle {
    
    double m_xPos;
    double m_yPos;
    
public:
    Particle();
    virtual ~Particle();
    
};

#endif /* Particle_hpp */
