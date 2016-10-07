#include "Tek_Game.h"
#include "PongMenuScene.h"

int main(int argc, char* args[]){
    Tek_Game game("TestApp", "0.0.0");
    PongMenuScene* pong = new PongMenuScene();
    game.setScene(pong);
    game.start();
    return 0;
}
