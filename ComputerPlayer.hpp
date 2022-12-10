#ifndef COMPUTERPLAYER_HPP
#define COMPUTERPLAYER_HPP

#include "Player.hpp"

class ComputerPlayer : public Player{
    public:
        ComputerPlayer();
        virtual Card getCard(Card::Suit suit, bool broken) const = 0;
};

#endif