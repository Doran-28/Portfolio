#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Deck.hpp"

class Player{
    public:
        // Added variables to track player scores
        int roundScore;
        int totalScore;

        const std::string name;

        Player(const std::string& name);
        virtual ~Player() = default;
        bool isValid(Card::Suit suit, bool broken, const Card& card) const;
        virtual Card getCard(Card::Suit suit, bool broken) const = 0;

        // extra functions
        void addToHand(Deck& d);
        void removeCard(const Card& c);

    protected:
        std::vector<Card> cards; // For the players hand
};

#endif