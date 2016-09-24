#ifndef TEK_SCENE_H
#define TEK_SCENE_H

class Tek_Game;
class Tek_InputManager;
class Tek_Graphics;

class Tek_Scene{
    public:
        /* void init
        *  @param1 Tek_Game* game
        */
        void init(Tek_Game* game);
        /* void loadAssets
        *  @param1 Tek_Graphics* graphics
        */
        void loadAssets(Tek_Graphics* graphics);
        /* void update
        *  @param1 float deltaTime
        */
        void update(float deltaTime);
        /* void render
        *  @param1 Tek_Graphics* graphics
        */
        void render(Tek_Graphics* graphics);
        /* void destroy
        */
        void destroy();

        /* void setScene
        *  @param1 Tek_Scene* scene
        */
        void setScene(Tek_Scene* scene);

    private:
        Tek_Game* _game; //
        Tek_InputManager* _input;
        /* virtual void initScene
        */
        void virtual initScene();
        /* virtual void loadSceneAssets
        *  @param1 Tek_Graphics* graphics
        */
        void virtual loadSceneAssets(Tek_Graphics* graphics);
        /* virtual void updateScene
        *  @param1 float deltaTime
        */
        void virtual updateScene(float deltaTime);
        /* virtual void renderScene
        *  @param1 Tek_Graphics* graphics
        */
        void virtual renderScene(Tek_Graphics* graphics);
        /* virtual void destroyScene
        */
        void virtual destroyScene();
};

#endif // TEK_SCENE_H
