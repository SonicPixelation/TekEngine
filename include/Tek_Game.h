#ifndef TEK_GAME_H
#define TEK_GAME_H

class Tek_Graphics;
class Tek_Scene;
class Tek_InputManager;

class Tek_Game
{
     public:
        /* Tek_Game
        *  @param1 const char* appId
        *  @param2 const char* appVersion
        */
        Tek_Game(const char* appId, const char* appVersion);

        /* void start
        */
        void start();
        /* void stop
        */
        void stop();

        //setters
        void setScene(Tek_Scene* newScene);
        //getters---------------------------------------
        const char* getAppId(){return _appId;}
        const char* getAppVersion(){return _appVersion;}
        //----------------------------------------------
        bool isRunning(){return _running;}
        //
        int getWidth(){return _Width;}
        int getHeight(){return _Height;}
        const char* getTitle(){return _Title;}
        bool isFullscreen(){return _Fullscreen;}
        //--------------------------------------------
        Tek_Graphics* getGraphics(){return _graphics;}
        Tek_Scene* getCurrentScene(){return _currentScene;}
        Tek_InputManager* getInputManager(){return _input;}

    private:
        const char* _appId;       //
        const char* _appVersion;  //
        //------------------------//
        bool _running;            //
        //------------------------//
        int _Width, _Height;      //
        const char* _Title;       //
        bool _Fullscreen;         //
        //------------------------//
        Tek_Graphics* _graphics;  //
        Tek_Scene* _currentScene; //
        Tek_InputManager* _input; //
        //------------------------//
        /* bool init
        */
        bool init();
        /* void run
        */
        void run();
        /* void update
        *  @param1 int deltaTime
        */
        void update(int deltaTime);
        /* void render
        *  @param1 Tek_Graphics* graphics
        */
        void render(Tek_Graphics* graphics);
        /* void destroy
        *  cleans up everything on the screen before
        *  the game is closed
        */
        void destroy();
};

#endif // TEK_GAME_H
