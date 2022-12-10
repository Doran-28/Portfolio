#ifndef RANDOMPLAYER_HPP
#define RANDOMPLAYER_HPP

#include "ComputerPlayer.hpp"

class RandomPlayer : public ComputerPlayer{
    public:
        Card getCard(Card::Suit suit, bool broken) const override;
};

#endif