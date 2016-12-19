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
#include "Screen.hpp"

struct Particle {
    
    double m_xPos;
    double m_yPos;
    double m_xSpeed;
    double m_ySpeed;
    
public:
    Particle();
    virtual ~Particle();
    void update();
    
};

#endif /* Particle_hpp */
