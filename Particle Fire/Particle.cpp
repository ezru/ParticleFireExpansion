//
//  Particle.cpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#include "Particle.hpp"

Particle::Particle(): m_xPos(0), m_yPos(0) {
    
    m_speed = (0.00015 * rand())/RAND_MAX;
    m_direction = (2.0 * M_PI) * rand()/RAND_MAX;
    
}

Particle::~Particle() {
    
    
    
}

void Particle::update(int interval) {
    
    m_xSpeed = m_speed * cos(m_direction);
    m_ySpeed = m_speed * sin(m_direction);
    
    m_xPos += m_xSpeed * interval;
    m_yPos += m_ySpeed * interval;

}