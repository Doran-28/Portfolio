#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(const std::string& name) : Player(name) {

}

// Returns the card that the human player has selected to play
// The selected card is checked from the isValid() funtion, and conitoulsy prompts user until
// a valid card has been selected.
Card HumanPlayer::getCard(Card::Suit suit, bool broken) const{
    int cardNum; // to inde the cards in the hand
    std::cout << "Your card selection:\n\n";

    for (int i = 0; i < cards.size(); ++i){
        std::cout << i + 1 << ": " << cards[i]; // Lists all cards in hand to user and their index
    }

    std::cout << std::endl << "Select Card:\n";
    std::cin >> cardNum;

    while ( std::cin.fail() || !isValid(suit, broken, cards[cardNum - 1]) ){ //checks whether card is valid or not
        std::cin.clear(); 
        std::cin.ignore();
        std::cout << "Selected card isn't valid, try again:\n";
        std::cin >> cardNum;
    }  
    return cards[cardNum - 1];
}
