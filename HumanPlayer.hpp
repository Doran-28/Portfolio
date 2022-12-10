#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"

class HumanPlayer : public Player{
    public:
        HumanPlayer(const std::string& name);
        Card getCard(Card::Suit suit, bool broken) const override;
};

#endif