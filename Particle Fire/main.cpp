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
    
    const Particle *const pParticle = swarm.getParticles();
    
    
    double angle = 0;
    double rads = 0;
    
    while (true) {
        

        //int elapsed = SDL_GetTicks();
        angle = angle + 1; //Increment angle by 1 everytime the loop runs.
        rads = angle*(Screen::PI/180);
        int red = (sin(rads) + 1)*127;
        int green = (sin(rads+90) + 1)*127;
        int blue = (sin(rads+180) + 1)*127;
        
        for (int i=0; i < Swarm::NPARTICLES; i++) {
            int xPos = (pParticle[i].m_xPos + 1)*Screen::SCREEN_WIDTH/2;
            int yPos = (pParticle[i].m_yPos + 1)*Screen::SCREEN_WIDTH/2;
            screen.setPixelColour(xPos, yPos, red, green, blue, 0);
        }
        
        screen.update();
        
        if (screen.processEvent() == false) {
            
            break;
            
        }
    }
    
    screen.close();
    
    return 0;
}
