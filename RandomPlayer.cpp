#include "RandomPlayer.hpp"


// Uses rand() function to select a random index in the players cards.
// Uses isValid() to return a proper playable card.
Card RandomPlayer::getCard(Card::Suit suit, bool broken) const {
    
    int randIdx = rand() % cards.size(); // Randomly selects index from players deck

    while ( !(isValid(suit, broken, cards[randIdx])) ){ // validates randomly selected index
        randIdx = rand() % cards.size();
    }

    return cards[randIdx]; //returns random card if valid

}