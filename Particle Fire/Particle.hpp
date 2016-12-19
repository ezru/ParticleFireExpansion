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
#include <math.h>
#include "Screen.hpp"

struct Particle {
    
    double m_xPos;
    double m_yPos;
    
private:
    double m_xSpeed;
    double m_ySpeed;
    double m_speed;
    double m_direction;
    
private:
    void init();
    
public:
    Particle();
    virtual ~Particle();
    void update(int interval);
    
};

#endif /* Particle_hpp */
