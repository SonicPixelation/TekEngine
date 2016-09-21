#ifndef TEK_GRAPHICS_H
#define TEK_GRAPHICS_H

class SDL_Window;
class SDL_Renderer;
class SDL_Surface;
class SDL_Texture;

class Tek_Graphics
{
    public:
        Tek_Graphics();


        /* bool createWindow
        *  @param1 int width; the width of the window in pixels
        *  @param2 int height; the height of the window in pixels
        *  @param3 const char* title; the title of the window
        */
        bool createWindow(int width, int height, const char* title);


        /* SDL_Texture* texture
        *  @param const char* filepath
        */
        SDL_Texture* loadTexture(const char* filepath);

    private:
    SDL_Window* _window;     //
    SDL_Renderer* _renderer; //

};

#endif // TEK_GRAPHICS_H
