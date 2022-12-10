#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <vector>


class Deck
{
    public:
        Deck();
        void reset(); 
        const Card draw(); 
        friend std::ostream& operator<<(std::ostream& os, const Deck d); 
        
    private:
        std::vector<Card> deck; 

};

#endif
