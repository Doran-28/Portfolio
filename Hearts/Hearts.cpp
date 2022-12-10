// Doran Williams
// 0406572

#include "Game.hpp"


int main(){ 
    
    Game game;
    game.selectPlayers();
    
    while (!game.isWinner()){
        game.play();
        game.announceWinner();
    }

}
