//
//  Particle.cpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#include "Particle.hpp"

Particle::Particle() {
    
    m_xPos = (2*(double)rand()/RAND_MAX) - 1;
    m_yPos = (2*(double)rand()/RAND_MAX) - 1;
    
}

Particle::~Particle() {
    
    
    
}