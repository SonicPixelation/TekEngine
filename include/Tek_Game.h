#ifndef TEK_GAME_H
#define TEK_GAME_H

class lua_State;
//
class Tek_Screen;

class Tek_Game
{
    public:
        Tek_Game();
        /* void start
        */
        void start();
        /* void stop
        */
        void stop();

        //getters-------------------------------
        int getWidth(){return _width;}
        int getHeight(){return _height;}
        const char* getTitle(){return _title;}
        bool isRunning(){return _running;}
        //--------------------------------------
        Tek_Screen* getScreen(){return _screen;}
    private:
        lua_State* _mainState;
        //--------------------
        int _width;
        int _height;
        const char* _title;
        bool _running;
        //-------------------
        Tek_Screen* _screen;
        //------------------


        //game engine fuctions-------
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
        *  @param Tek_Screen* screen
        */
        void render(Tek_Screen* screen);
        /* void destroy
        */
        void destroy();
};

#endif // TEK_GAME_H
