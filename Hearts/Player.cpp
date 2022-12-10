#include "Player.hpp"

// Sets the players name as a constant string
Player::Player(const std::string& name) : name(name) { 
    roundScore = 0;
    totalScore = 0;
    };

// Function returns if card is valid base on the suit it's asking for and ff hearts has been broken or not
// suit none means the player is leading and select any cardcfrom his hand (H depends on broken status)
bool Player::isValid(Card::Suit suit, bool broken, const Card& card) const{    // For-loop checks players hand to check if they have the correct suit or not
    bool flag = false;

    // suit = none if its the first players move, and they can lead with any suit (H suit is dependable on broken status)
    if (suit == Card::Suit::None){

        if (broken == true)
            return true; // Returns true because any card selecred here would be valid 

        if (broken == false && card.suit != Card::Suit::None)
            return true;
        else
            return false;
    }

    for (int i = 0; i < cards.size(); ++i){ // Sets flag to true if the the player has the desired suit in their hand
        if(cards[i].suit == suit)
            flag = true;
    }

    // If player has correct suit
    if (flag == true){ 
        if (card.suit == suit)
            return true;
    }
    // If player doesn't have correct suit, they are allowed to play any suit, including hearts
    else
        return true;
    // False placement if the player selects a card that doen't comply with the rules
    return false;
}

// Added function to add cards from a deck to a players hand
void Player::addToHand(Deck& d){
    cards.push_back(d.draw()); // draw() removes card from top of deck
}

// Added function to remove a card from a players hand
void Player::removeCard(const Card& c) {
    for (int i = 0; i < cards.size(); ++i){
        if (cards[i].suit == c.suit && cards[i].value == c.value){
            cards.erase(cards.begin() + i);
            return;
        } 
    }
}