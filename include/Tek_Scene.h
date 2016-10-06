#ifndef TEK_SCENE_H
#define TEK_SCENE_H



class Tek_Graphics;
class Tek_Game;
class Tek_InputManager;

class Tek_Scene
{
    public:
        /* void initAssets
        *  @param Tek_Graphics* graphics
        */
        void initAssets(Tek_Graphics* graphics);
        /* void init
        *  @param Tek_Game* game
        */
        void init(Tek_Game* game);
        /* void update
        *  @param int deltaTime
        */
        void update(int deltaTime);
        /* void render
        *  @param Tek_Graphics* graphics
        */
        void render(Tek_Graphics* graphics);
        /* void destroy
        */
        void destroy();

        //setters
        void setScene(Tek_Scene* newScene);

        //getters
        Tek_Game* getGame(){return _game;}
        Tek_InputManager* getInputManger(){return input;}

    protected:
        virtual void initSceneAssets(Tek_Graphics* graphics);
        virtual void initScene();
        virtual void updateScene(int delatTime);
        virtual void renderScene(Tek_Graphics* graphics);
        virtual void destroyScene();
    private:
        Tek_Game* _game;
        Tek_InputManager* input;
};

#endif // TEK_SCENE_H
