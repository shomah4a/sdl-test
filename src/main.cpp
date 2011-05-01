// -*- coding:utf-8 -*-
#include <iostream>
#include <vector>
#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>

#include <boost/thread.hpp>

#include "main.hpp"


/// モード一覧
void list_modes(void)
{
    auto modes = ::SDL_ListModes(NULL, SDL_HWSURFACE|SDL_GL_DOUBLEBUFFER|SDL_OPENGL);

    if (!modes)
    {
        std::cerr << "no modes available" << std::endl;
        exit(1);
    }

    if (modes == (decltype(modes))-1)
    {
        std::cerr << "all modes available" << std::endl;
    }
    else
    {
        for (; modes; modes++)
        {
            std::cerr << (*modes)->w << 'x' << (*modes)->h << std::endl;
        }
    }
}



/// スクリーン初期化
::SDL_Surface* init_screen(void)
{
    const auto info = ::SDL_GetVideoInfo();

    const int bpp = info->vfmt->BitsPerPixel;

    ::SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    ::SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    ::SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    ::SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    ::SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    ::SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

    ::SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 8);
    ::SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8);
    ::SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8);
    ::SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8);

    // しぬ
    // ::SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    // ::SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);

    auto screen = ::SDL_SetVideoMode(640, 480, bpp, SDL_HWSURFACE|SDL_GL_DOUBLEBUFFER|SDL_OPENGL);

    if (!screen)
    {
        std::cerr << "screen initialize failed" << std::endl;
        exit(1);
    }

    return screen;
}



void draw(void)
{
    ::glClearColor(255, 255, 255, 255);

    ::SDL_GL_SwapBuffers();
}



void drawing_thread(void)
{
    while (1)
    {
        draw();
    }
}



int main(const int argc, const char* const args[])
{   
    // initialize
    if (::SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "SDL initialize failed" << std::endl;
        return 1;
    }

    std::atexit(::SDL_Quit);

    // screen init
    auto screen = init_screen();

    // boost::thread th(drawing_thread);

    // drawing_thread();
    
    std::cout << "hello, sdl" << std::endl;
    
    return 0;
}


