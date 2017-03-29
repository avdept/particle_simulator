//
// Created by  Alex on 3/27/17.
//

#include "Screen.h"


Screen::Screen() : m_window(NULL), m_render(NULL), m_texture(NULL), m_buffer(NULL) {

}


bool Screen::init(){
    const int WINDOW_HEIGHT = 600;
    const int WINDOW_WIDHT = 800;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Sdl init failed" << endl;
        return false;
    }

    m_window = SDL_CreateWindow("Particle Simulator", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, WINDOW_WIDHT,
                                          WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (m_window == NULL) {
        SDL_Quit();
        return false;
    }

    m_render  = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (m_render == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    m_texture = SDL_CreateTexture(m_render, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDHT, WINDOW_HEIGHT);

    if(m_texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(m_render);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }


    Uint32 *buffer = new Uint32[WINDOW_WIDHT * WINDOW_HEIGHT];

    memset(buffer, 0x0, WINDOW_WIDHT*WINDOW_HEIGHT*sizeof(Uint32));
    buffer[30000] = 0x0000FF;

    for(int i=0; i< WINDOW_HEIGHT*WINDOW_WIDHT; i++) {
        buffer[i] = 0xFFFFFFFF;
    }

    SDL_UpdateTexture(m_texture, NULL, buffer, WINDOW_WIDHT * sizeof(Uint32));
    SDL_RenderClear(m_render);
    SDL_RenderCopy(m_render, m_texture, NULL, NULL);
    SDL_RenderPresent(m_render);
    return true;

}
bool Screen::processEvents(){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) {
                return false;
            }
        }

    return true;
}
void Screen::close() {
    delete []m_buffer;

    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_render);
    SDL_DestroyWindow(m_window);

    SDL_Quit();
}

