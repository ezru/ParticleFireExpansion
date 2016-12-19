//
//  Swarm.cpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#include "Swarm.hpp"

Swarm::Swarm() {
    
    m_pParticle = new Particle[NPARTICLES];
    
}

Swarm::~Swarm() {
    
}

void Swarm::update() {
    for (int i=0; i < Swarm::NPARTICLES; i++) {
        m_pParticle[i].update();
    }
    
}