#ifndef GAME_HPP
#define GAME_HPP

#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"

class Game{
    public: 

        Game() = default;
        ~Game() = default; // Default because unique_ptr automatically deletes memory when out of scope
        void selectPlayers();
        std::unique_ptr<Player>& nextPlayer();    
        void play();
        void announceWinner();

        // Three added helper functions 
        int playerNumToInt(const std::unique_ptr<Player>& p);
        std::unique_ptr<Player>& intToPlayerNum(int i);
        bool isWinner();

        private:
        std::unique_ptr<Player> p1;
        std::unique_ptr<Player> p2;
        std::unique_ptr<Player> p3;
        std::unique_ptr<Player> p4;
};


#endif