//
//  main.cpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Screen.hpp"
#include "Swarm.hpp"

using std::cout;
using std::endl;


int main(int argc, const char * argv[]) {
    
    srand((double)time(NULL));
    
    Screen screen;
    if (screen.init() == false) {
        
        cout << "Screen failed to initialise" << endl;
        return 1;
    }
    
    Swarm swarm;
    
    //double angle = 0;
    //double rads = 0;
    
    while (true) {
        
        int elapsed = SDL_GetTicks();
        
        swarm.update(elapsed);
        
       // angle = angle + 1; //Increment angle by 1 everytime the loop runs.
        //rads = angle*(Screen::PI/180);
        int red = (sin(elapsed * 0.0002) + 1)*128;
        int green = (sin(elapsed * 0.0003) + 1)*128;
        int blue = (sin(elapsed * 0.0005) + 1)*128;
        
        const Particle *const pParticle = swarm.getParticles();
        
        for (int i=0; i < Swarm::NPARTICLES; i++) {
            
            Particle particle = pParticle[i];
            
            int xPos = (particle.m_xPos + 1)*Screen::SCREEN_WIDTH/2;
            int yPos = particle.m_yPos * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;
            
            screen.setPixelColour(xPos, yPos, red, green, blue, 0);
        }
        
        screen.update();
        screen.clear();
        
        if (screen.processEvent() == false) {
            
            break;
            
        }
    }
    
    screen.close();
    
    return 0;
}
