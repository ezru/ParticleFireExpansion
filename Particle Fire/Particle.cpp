//
//  Particle.cpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#include "Particle.hpp"

Particle::Particle() {
    
    m_xPos = (2.0 * rand()/RAND_MAX) - 1;
    m_yPos = (2.0 * rand()/RAND_MAX) - 1;
    
    m_xSpeed = 0.002 * ((2.0 * rand()/RAND_MAX) - 1);
    m_ySpeed = 0.002 * ((2.0 * rand()/RAND_MAX) - 1);
    
}

Particle::~Particle() {
    
    
    
}

void Particle::update() {
    
    m_xPos += m_xSpeed;
    m_yPos += m_ySpeed;
    
    if (m_xPos <= -1.0 || m_xPos >= 1.0) {
        m_xSpeed = -m_xSpeed;
    }
    
    if (m_yPos <= -1.0 || m_yPos >= 1.0) {
        m_ySpeed = -m_ySpeed;
    }
}