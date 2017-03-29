//
// Created by  Alex on 3/27/17.
//
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

#ifndef PARTICLESIMULATION_SCREEN_H
#define PARTICLESIMULATION_SCREEN_H


class Screen {
public:
    const static int WINDOW_HEIGHT = 600;
    const static int WINDOW_WIDHT = 800;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_render;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
public:
    Screen();
    bool init();
    bool processEvents();
    void close();
};


#endif //PARTICLESIMULATION_SCREEN_H
