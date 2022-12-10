#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <cstring>

struct Card
{
    enum class Suit {Spade = 'S', Heart = 'H', Club = 'C', Diamond = 'D', None}; // 'A' stands for "Any" as in any suit
    Suit suit; // represents card suit
    int value; // represents card value
    friend std::ostream &operator<<(std::ostream &os, const Card card);
}; 

#endif