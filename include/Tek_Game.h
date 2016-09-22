#ifndef TEK_GAME_H
#define TEK_GAME_H

class Tek_Graphics;
class Tek_Scene;
class Tek_Game
{
    public:
        Tek_Game(const char* appId, const char* appVersion);

        /* void start
        */
        void start();

        /* void stop
        */
        void stop();
        /* void setScene
        *  @param1 Tek_Scene* scene
        */

        //setters
        void setScene(Tek_Scene* scene);
        void setWindowSize(int width, int height);
        void setWindowTitle(const char* title);

        //getters
        int getWidth(){return _Width;}
        int getHeight(){return _Height;}
        const char* getTitle(){return _Title;}

    private:
        const char* _appId;      // The unique id of the application
        const char* _appVersion; // The unique version of the current application iteration
        //----------------------------
        int _Width;              // The width in pixels of the screen
        int _Height;             // The height in pixels of the screen
        const char* _Title;      // The title of the screen
        bool _running;           // If this is true the main loop will continue to process, if not the loop will break and the application will terminate
        Tek_Graphics* _graphics; //
        Tek_Scene* _currentScene;//
        //----------------------------
        /* bool init
        */
        bool init();
        /* void run
        */
        void run();
        /* void update
        *  @param float deltaTime
        */
        void update(float deltaTime);
        /* void render
        *  @param Tek_Graphics* graphics
        */
        void render(Tek_Graphics* graphics);
        /* void destroy
        */
        void destroy();
};

#endif // TEK_GAME_H
