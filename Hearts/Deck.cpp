#include "Deck.hpp"
#include <random>

Deck::Deck(){
    reset();
}

void Deck::reset(){
    Card card;
    deck.clear();

    for (int i = 2; i <=14; ++i){
        card.value = i;
        card.suit = Card::Suit::Club;
        deck.push_back(card);
    }
    for (int i = 2; i <=14; ++i){
        card.value = i;
        card.suit = Card::Suit::Spade;
        deck.push_back(card);
    }
    for (int i = 2; i <=14; ++i){
        card.value = i;
        card.suit = Card::Suit::Diamond;
        deck.push_back(card);
    }
    for (int i = 2; i <=14; ++i){
        card.value = i;
        card.suit = Card::Suit::Heart;
        deck.push_back(card);
    }
   // Radomly shuffles the deck. New random shuffle each time funtion is called 
   std::shuffle(std::begin(deck), std::end(deck), std::default_random_engine(std::random_device{}() ));
}

// Dacks top card off the deck and returns it
const Card Deck::draw(){
    Card temp = deck.back();
    deck.pop_back();
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Deck d){
    for (int i = 0; i < d.deck.size(); ++i){
        os << d.deck[i];
    }
    os << d.deck.size() << "\n";
    return os;
}

