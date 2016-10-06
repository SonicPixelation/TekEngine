#include "Tek_Scene.h"
#include "Tek_Graphics.h"
#include "Tek_Game.h"

void Tek_Scene::initAssets(Tek_Graphics* graphics){
    initSceneAssets(graphics);
}

void Tek_Scene::init(Tek_Game* game){
    this->_game = game;
    this->input = game->getInputManager();
    initScene();
}

void Tek_Scene::update(int deltaTime){
    updateScene(deltaTime);
}

void Tek_Scene::render(Tek_Graphics* graphics){
    renderScene(graphics);
}

void Tek_Scene::destroy(){
    destroyScene();
}


//setters
void Tek_Scene::setScene(Tek_Scene* newScene){
    getGame()->setScene(newScene);
}
