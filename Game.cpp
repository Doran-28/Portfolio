#include "Game.hpp"

int trickWinner; // Used to keep track of who won the trick, and is playing next;l.

int points(const Card& c);

// Function prompts user to select player types (human or computer)
// Will contiously prompt user until there's a valid input (h or c)
void Game::selectPlayers(){
   
    std::cout << "Select 4 kind of players for the game (h or c):\n";
    char playerType; // Tracks the player type
    std::string name; // Name for human player

    for (int i = 0; i < 4; ++i){ // Sets the four players
        
        // Promts for correcr user input
        std::cout << "Select player kind (h or c): ";
        std::cin >> playerType;
        playerType = tolower(playerType);

        while (playerType != 'h' && playerType != 'c'){ // Checks for right input by user
            std::cin.clear(); 
            std::cin.ignore();
            std::cout << "Invalid input, try again: ";
            std::cin >> playerType;
            playerType = tolower(playerType);
        }

        switch (i) { // Switch statement used to initalize p1,p2,p3,p4 pointers
                    // Each case has if-else wheter to initalize a human or computer player
            case 0:
                if (playerType == 'h'){ //Enters name for human, and creates player
                    std::cout << "Enter name for human player: ";
                    std::cin >> name;
                    p1 = std::unique_ptr<Player>(new HumanPlayer(name));
                    std::cout << "Human player created!\n";
                }
                else{ // Creates computer player
                    p1 = std::unique_ptr<Player>(new RandomPlayer());
                    std::cout << "Computer player created!\n";
                }
                break;
            case 1:
                if (playerType == 'h'){ //Enters name for human, and creates player
                    std::cout << "Enter name for human player: ";
                    std::cin >> name;
                    p2 = std::unique_ptr<Player>(new HumanPlayer(name));
                    std::cout << "Human player created!\n";
                }
                else{ // Creates computer player
                    p2 = std::unique_ptr<Player>(new RandomPlayer());                   
                    std::cout << "Computer player created!\n";
                }
                break;
            case 2:
                if (playerType == 'h'){ //Enters name for human, and creates player
                    std::cout << "Enter name for human player: ";
                    std::cin >> name;
                    p3 = std::unique_ptr<Player>(new HumanPlayer(name));
                    std::cout << "Human player created!\n";
                }
                else{ // Creates computer player
                    p3 = std::unique_ptr<Player>(new RandomPlayer()); 
                    std::cout << "Computer player created!\n";
                }
                break;
            case 3:
                if (playerType == 'h'){ //Enters name for human, and creates player
                    std::cout << "Enter name for human player: ";
                    std::cin >> name;
                    p4 = std::unique_ptr<Player>(new HumanPlayer(name));
                    std::cout << "Human player created!\n";
                }
                else{ // Creates computer player
                    p4 = std::unique_ptr<Player>(new RandomPlayer()); 
                    std::cout << "Computer player created!\n";
                }
                break;            
        }

    }
}

// Function returns pointer to a player if they won the trick
// Player wins trick by having highest value for the leading suit played
std::unique_ptr<Player>& Game::nextPlayer(){
    return intToPlayerNum(trickWinner);    
}

void Game::play(){
    // Creates and shuffles the deck
    Deck deck;
    // Deals entire deck to the 4 players
    for(int i = 0; i < 13; ++i){ 
        for (int j = 0; j < 4; ++j){
            switch (j){
                case 0:
                    p1->addToHand(deck);  
                    break; 
                case 1:
                    p2->addToHand(deck); 
                    break; 
                case 2:
                    p3->addToHand(deck);  
                    break; 
                case 3:
                    p4->addToHand(deck);  
                    break;     
            }
        }
    }
    std::cout << std::endl;


    // Players play cards in correct order;
    bool broken = false; // Keeps track if hearts is broken
    Card temp; // Used to print the card that was previously played
    int tempScore = 0; // Used to keep track of points for each trick
    Card firstPlayed; // Keeps track of what suit following players have to follow

    int highestVal; // Alse used to keep track of wins the trick by keeping track of highest card

    // Next 4 blocks of code is to play the first round, starts from whoever was created first.
    std::cout << p1->name << "'s lead\n";
    firstPlayed = p1->getCard(Card::Suit::None, broken); // First move, so 'A' means any suit and hearts isn't broken
    tempScore += points(firstPlayed); // Adds points for the trick
    p1->removeCard(firstPlayed); // Removes card frok players hand
    std::cout << p1->name << " played: " << firstPlayed << "\n";

    std::cout << p2->name << "'s turn\n";
    temp = p2->getCard(firstPlayed.suit, broken);
    p2->removeCard(temp);
    tempScore += points(temp);
    std::cout << p2->name << " played: " << temp << "\n";
    
    if ( temp.suit == firstPlayed.suit && temp.value > firstPlayed.value ){
        trickWinner = playerNumToInt(p2);
        highestVal = temp.value;
    }
    else {
        trickWinner = playerNumToInt(p1);
        highestVal = firstPlayed.value;
    }

    std::cout << p3->name << "'s turn\n";    
    temp = p3->getCard(firstPlayed.suit, broken);
    tempScore += points(temp);
    p3->removeCard(temp);
    std::cout << p3->name << " played: " << temp << "\n";
   
    if ( temp.suit == firstPlayed.suit && temp.value > highestVal ){
        trickWinner = playerNumToInt(p3);
        highestVal = temp.value;
    }

    std::cout << p4->name << "'s turn\n";
    temp = p4->getCard(firstPlayed.suit, broken);
    tempScore += points(temp);
    p4->removeCard(temp);
    std::cout << p4->name << " played: " << temp << "\n";

    if ( temp.suit == firstPlayed.suit && temp.value > highestVal ){
        trickWinner = playerNumToInt(p4);
        highestVal = temp.value;
    }

    intToPlayerNum(trickWinner)->roundScore += tempScore;
    tempScore = 0;


    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";

    for (int i = 0; i < 12; ++i ){ // Theres 12 rounds played after the first round
        
        std::cout << nextPlayer()->name << "'s lead\n";
        firstPlayed = nextPlayer()->getCard(Card::Suit::None, broken); // Player who gained most points goes first
        tempScore += points(firstPlayed);
        nextPlayer()->removeCard(firstPlayed);
        std::cout << nextPlayer()->name << " played: " << firstPlayed << "\n";
        highestVal = firstPlayed.value;
       
        for (int j = playerNumToInt(nextPlayer()) + 1, c = 0; c < 3; ++j, ++c){ // next three players go in order inside this for-loop
            
            if (j > 4) j = 1; // Used to circle through the players (Ex. p3,p4,p1,p2)

            std::cout << intToPlayerNum(j)->name << "'s turn\n";
            temp = intToPlayerNum(j)->getCard(firstPlayed.suit, broken);
            tempScore += points(temp);

            if (temp.suit == Card::Suit::Heart) broken = true; // people are allowed to play hearts now once someone played a heart

            intToPlayerNum(j)->removeCard(temp);
            std::cout << intToPlayerNum(j)->name << " played: " << temp << "\n";

            if ( temp.suit == firstPlayed.suit && temp.value > highestVal ){
                trickWinner = j;
                highestVal = temp.value;
            }
        }

        intToPlayerNum(trickWinner)->roundScore += tempScore; // increments trick winner temp score
        //intToPlayerNum(trickWinner)->totalScore += tempScore; // increments trick winner overall score

        tempScore = 0;

        std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
    }
    // For loop check if someone shot the moon
    // This happens if a player gets every single point possible per round
    for (int i = 1; i <=4; ++i){ 
        if (intToPlayerNum(i)->roundScore == 26){ 
            std::cout << "Player " << intToPlayerNum(i)->name << " Shot the Moon!\n";
            intToPlayerNum(i)->roundScore = 0;
            switch (i) {
                case 1:
                    p2->roundScore = 26;
                    p3->roundScore = 26;
                    p4->roundScore = 26;
                    break;
                case 2:
                    p1->roundScore = 26;
                    p3->roundScore = 26;
                    p4->roundScore = 26;    
                    break;               
                case 3:
                    p1->roundScore = 26;
                    p2->roundScore = 26;
                    p4->roundScore = 26;    
                    break;                
                case 4:
                    p1->roundScore = 26;
                    p2->roundScore = 26;
                    p3->roundScore = 26;    
                    break;
            }
            break;
        }
    }
    p1->totalScore += p1->roundScore;
    p2->totalScore += p2->roundScore;
    p3->totalScore += p3->roundScore;
    p4->totalScore += p4->roundScore;

}

void Game::announceWinner(){

    if ( isWinner() ) {
        std::cout << "GAME OVER!\n";
        std::cout << "Final scores:\n";
        std::cout << p1->name << ": " << p1->totalScore << "\n";
        std::cout << p2->name << ": " << p2->totalScore << "\n";
        std::cout << p3->name << ": " << p3->totalScore << "\n";
        std::cout << p4->name << ": " << p4->totalScore << "\n";
        return;
    }

    std::cout << "Scores from round:\n";
    std::cout << p1->name << ": " << p1->roundScore << "\n";
    std::cout << p2->name << ": " << p2->roundScore << "\n";
    std::cout << p3->name << ": " << p3->roundScore << "\n";
    std::cout << p4->name << ": " << p4->roundScore << "\n\n";

    std::cout << "Total scores:\n";
    std::cout << p1->name << ": " << p1->totalScore << "\n";
    std::cout << p2->name << ": " << p2->totalScore << "\n";
    std::cout << p3->name << ": " << p3->totalScore << "\n";
    std::cout << p4->name << ": " << p4->totalScore << "\n\n";

    p1->roundScore = 0;
    p2->roundScore = 0;
    p3->roundScore = 0;
    p4->roundScore = 0;

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
}

bool Game::isWinner() {
    for (int i = 1; i <=4; ++i){
        if (intToPlayerNum(i)->totalScore >= 80 )
            return true;
    }
    return false;
}
// Simple function to see how many points a card has
int points(const Card& c) {
    int temp = 0;
    if (c.suit == Card::Suit::Heart)
        ++temp;
    if (c.suit == Card::Suit::Spade && c.value == 12)
        temp += 13;
    return temp;
}

// Converts player number into integer, for easy traversal in the play() function
int Game::playerNumToInt(const std::unique_ptr<Player>& p)  {
    if (p == p1)
        return 1;
    if (p == p2)
        return 2;
    if (p == p3)
        return 3;
    if (p == p4)
        return 4;
    return 0; // Should never reach this part of code, but it's here for default return value
}
// Coverts int into player number for easy traversal in the play() function
std::unique_ptr<Player>& Game::intToPlayerNum(int i)  {
    if (i == 1)
        return p1;
    if (i == 2)
        return p2;
    if (i == 3)
        return p3;
    if (i == 4)
        return p4;

    // This code below would never be reached,  It's here to remove warnings when compiling
    //p1 = nullptr;
    return p1;
}