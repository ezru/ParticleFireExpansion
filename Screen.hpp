//
//  Screen.hpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>

class Screen {
public:
    Screen();
    
    bool init();
    bool processEvent();
    void setPixelColour(int xPos, int yPos, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
    void update();
    void clear();
    void close();
    
public:
    const int static SCREEN_WIDTH = 800;
    const int static SCREEN_HEIGHT = 600;
    constexpr const double static PI = 3.1415926535897;
    
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
    
    double angle;
    
};

#endif /* Screen_hpp */
