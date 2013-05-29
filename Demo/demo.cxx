#include <iostream>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <SDL.h>
#include "exceptions.hpp"

EGLDisplay egl_display;

void init_egl_context()
{
	//Get an EGL display connection
	egl_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if(egl_display == EGL_NO_DISPLAY)
        throw EGLException("eglGetDisplay");
                
    // Initialize the EGL display connection:
    EGLConfig config;
    {
        EGLint num_config;
        static const EGLint attribute_list[] = 
        {
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 8,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_NONE
        };
        
         if(eglChooseConfig(egl_display, attribute_list, &config, 1, &num_config) == EGL_FALSE)
            throw EGLException("eglChooseConfig");
    }
}


int main(int argc, char* argv[])
{
    //ESContext esContext;
    init_egl_context();
    std::cout << "Hello, new world!\n";
}
