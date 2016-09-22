#ifndef TEK_GRAPHICS_H
#define TEK_GRAPHICS_H

class SDL_Window;
class SDL_Renderer;
class SDL_Surface;
class SDL_Texture;
class SDL_Rect;

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

        /* void destroyWindow
        */
        void destroyWindow();

        /* void updateWindow
        *  @param const char* title
        */
        void updateWindow(const char* title);
        /* void updateWindow
        *  @param1 int width
        *  @param2 int height
        */
        void updateWindow(int width, int height);
        /* void updateWindow
        *  @param1 int width
        *  @param2 int height
        *  @param3 const char* title
        */
        void updateWindow(int width, int height, const char* title);
        /* void clearScreen
        */
        void clearScreen();
        /* void flipScreen
        */
        void flipScreen();

        /* void draw
        *  @param1 SDL_Texture* texture
        *  @param2 SDL_Rect* srcRect
        *  @param3 SDL_Rect* dstRect
        */
        void drawTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect);

        /*
        */
        void drawTexture(SDL_Texture* texture, int srcX, int srcY, int srcW, int scrH, int x, int y, int w, int h);
        void drawTexture(SDL_Texture* texture, int x, int, int w, int h);

        /* SDL_Texture* texture
        *  @param const char* filepath
        */
        SDL_Texture* loadTexture(const char* filepath);

        //setters
        //getters
        SDL_Window* getWindow(){return _window;}
        SDL_Renderer* getRenderer(){return _renderer;}

    private:
    SDL_Window* _window;     //
    SDL_Renderer* _renderer; //

};

#endif // TEK_GRAPHICS_H
