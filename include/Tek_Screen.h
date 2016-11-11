#ifndef TEK_SCREEN_H
#define TEK_SCREEN_H


class SDL_Window;
class SDL_Renderer;
class SDL_Texture;
class SDL_Rect;
//
class Tek_Screen
{
    public:
        Tek_Screen();

        /*bool create Screen
        * @param int width
        * @param int height
        * @param const char* title
        */
        bool createScreen(int width, int height, const char* title);
        /* void updateTitle
        *  @param const char* title
        */
        //---------------------------------------
        /* void clearScreen
        */
        void clearScreen();

        /* void flipScreenBuffer
        */
        void flipScreenBuffer();
        /* void drawTexture
        *  @param SDL_Texture* texture
        *  @param SDL_Rect* srcRect
        *  @param SDL_Rect* dstRect
        */
        void drawTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* dstRect);
        //---------------------------------------
        /* SDL_Texture* loadTexture
        *  @param const char* filepath
        */
        SDL_Texture* loadTexture(const char* filepath);
        //----------------------------------------
        void updateTitle(const char* title);
        /* void updateSize
        *  @param int width
        *  @param int height
        */
        void updateSize(int width, int height);
        //----------------------------------------
        void destroy();
        //getters
        SDL_Window* getSDLWindow(){return _window;}
        SDL_Renderer* getSDLRenderer(){return _renderer;}
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
};

#endif // TEK_SCREEN_H
