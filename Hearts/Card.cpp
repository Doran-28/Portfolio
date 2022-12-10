#include "Card.hpp"


std::ostream &operator<<(std::ostream &os, const Card card)
{
    // Switch statement for converting the card value into face cards
    switch (card.value)
    {
    case 14:
        os << 'A' << "-" << static_cast<char>(card.suit) << std::endl;
        return os;
        break;
    case 11:
        os << 'J' << "-" << static_cast<char>(card.suit) << std::endl;
        return os;
        break;
    case 12:
        os << 'Q' << "-" << static_cast<char>(card.suit) << std::endl;
        return os;
        break;
    case 13:
        os << 'K' << "-" << static_cast<char>(card.suit) << std::endl;
        return os;
        break;
    default:
        os << card.value << "-" << static_cast<char>(card.suit) << std::endl;
        return os;
    }
}