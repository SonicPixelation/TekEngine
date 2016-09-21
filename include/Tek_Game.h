#ifndef TEK_GAME_H
#define TEK_GAME_H

class Tek_Graphics;

class Tek_Game
{
    public:
        Tek_Game(const char* appId, const char* appVersion);

        /* void start
        *
        */
        void start();

        /* void stop
        *
        */
        void stop();
    protected:
    private:
        const char* _appId;      // The unique id of the application
        const char* _appVersion; // The unique version of the current application iteration
        //
        int _Width;              // The width in pixels of the screen
        int _Height;             // The height in pixels of the screen
        const char* _Title;      // The title of the screen
        bool _running;           // If this is true the main loop will continue to process, if not the loop will break and the application will terminate


        void init();
        void run();
        void update(float deltaTime);
        void render(Tek_Graphics* graphics);
};

#endif // TEK_GAME_H
