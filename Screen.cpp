//
//  Screen.cpp
//  Particle Fire
//
//  Created by Israel Goitom on 12/12/2016.
//  Copyright © 2016 Wet Cat and Little Lamb. All rights reserved.
//

#include "Screen.hpp"

using std::cout;
using std::endl;

Screen::Screen(): m_window(NULL), angle(1) {}

bool Screen::init() {
    
    SDL_Init(SDL_INIT_VIDEO);
    
    m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (m_window == NULL) {
        
        cout<< "Can't create window" << endl;
        return false;
        
    }
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == NULL) {
        
        cout << "Can't dreate renderer" << endl;
        return false;
        
    }
    
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (m_texture == NULL) {
        
        cout << "Can't create texture" << endl;
        return false;

    }
    
    m_buffer1 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
    m_buffer2 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
    
    memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    
    return true;
}

bool Screen::processEvent() {
    
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::setPixelColour(int xPos, int yPos, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) {
    
    if (xPos < 0 || xPos >= Screen::SCREEN_WIDTH || yPos < 0 || yPos >= Screen::SCREEN_HEIGHT) {
        return;
    }
    
    Uint32 colour;
    
    colour += red;
    colour <<= 8;
    colour += green;
    colour <<= 8;
    colour += blue;
    colour <<= 8;
    colour += alpha;
    
    m_buffer1[(yPos*SCREEN_WIDTH)+xPos] = colour;
}

void Screen::blurBox() {
    
    Uint32 * temp;
    temp = m_buffer2;
    m_buffer2 = m_buffer1;
    m_buffer1 = temp;
    
    
    for (int yPos = 0; yPos < SCREEN_HEIGHT; yPos++) {
        for (int xPos = 0; xPos < SCREEN_WIDTH; xPos++) {
            
            /*
             * 0 0 0
             * 0 1 0
             * 0 0 0
             */
            
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            
            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    int currentX = xPos + col;
                    int currentY = yPos + row;
                    
                    //cout << " Current x: " << currentX << ",   "<< "xPos: " << xPos << endl;
                    //cout << " Current y: " << currentY << ",   "<< "yPos: " << yPos << endl;

                    
                    if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >=0 && currentY < SCREEN_HEIGHT) {
                        
                        Uint32 colour = m_buffer2[currentY*SCREEN_WIDTH +currentX];
                        
                        Uint8 red = colour >> 24;
                        Uint8 green = colour >> 16;
                        Uint8 blue = colour >> 8;
                        
                        totalRed += red;
                        totalGreen += green;
                        totalBlue += blue;
                        
                    }
                }
            }
            
            Uint8 red = totalRed/9;
            Uint8 green = totalGreen/9;
            Uint8 blue = totalBlue/9;
            Uint8 alpha = 0;
            
            setPixelColour(xPos, yPos, red, green, blue, alpha);
             
             
            
        }
    }
    
}

void Screen::update() {
    
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::close() {
    
    delete [] m_buffer1;
    delete [] m_buffer2;
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_Quit();
}