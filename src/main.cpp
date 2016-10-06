#include "Tek_Game.h"
#include "TestScene.h"

int main(int argc, char* args[]){
    Tek_Game game("TestApp", "0.0.0");
    TestScene* testScene = new TestScene();
    game.setScene(testScene);
    game.start();
    return 0;
}
