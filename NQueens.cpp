// Doran Williams, 0406572
#include <iostream>
#include <stack>
#include <cmath>
#include <string>

int userInput();
void solve(int, int[14]);
void print(int, int[14], int);
std::string notation(int, int);

int main(){
    unsigned short int N;
    N = userInput();
    int board[14] = {}; // Initializing board
    solve(N, board);

}

// returns N (0 - 14), that will determine the chess board size
// and number of queens.
int userInput(){

    int N;
    std::cout << "Enter a value greater than 0 and less than 14\n";
    std::cin >> N;
    while ((N <= 0 || N > 14) || std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore();
        std::cout << "Enter a value greater than 0 and less than 14\n";
        std::cin >> N;
    }
    return N;
}

// Function that checks if the current value can succesfully be placed
// The if-statement deteremines there's no duplicates, and no consecitve numbers within the board 
// e.g [1,2,4,3] would return false 1,2 & 4,3 are consective
// which translates to avalid queen placement on a chess board
// If function returns true, the 'current' value will be added to the 'stack' and the 'board'
bool valid(const std::stack<int>& stack, int current, int board[14]){
    for (int i = 0; i < stack.size(); i++){ 
        // Iterates through board values that, which is same as stack height
        if (board[i] == current || abs(current - board[i]) == stack.size() - i)
            return false;
        
    }
    return true;
    
}

// Function uses stacks, to keep track of solutions for the chess board
void solve(int N, int board[14]){
    int current = 0; // Current is used to keep track of the array index. Is column number
    int solutions = 0; // Counts number of solutions
    std::stack<int> stack; // Uses stack to keep track of solutions

    while (1 == 1){ // Does while loop until reaches break statement
        while(current < N){ //
            if (valid(stack, current, board) == true){ //if placement is valid, add current to stack.
                stack.push(current);
                board[stack.size() - 1] = current; // saves to board of valid placements
                current = 0; // resets current to ensure every possible occurance is found

            }
            else // if placement isn't valid, increment counter.
                current++;
        }
        if (stack.size() == N){ // if there's a solutiuon found, print and increment solutions
            print(++solutions, board, N);
        }
        if (stack.empty()) // Ends the function, if reached here, you found all possible solutions
            break;

        current = stack.top() + 1;  // updates current, then goes back into loop and starts backtracking
        stack.pop();    
    }
}

// Prints the solution for one board, and solution number.
// Uses notation funtion to print in proper chess notation
void print(int solutions, int board[14], int N){
    std::cout << "For solution: " << solutions << ": \n";
    for (int i = 0;i < N; i++){ // The for-loop iterates each row, and reads from the board[] for the column index
        std::cout << notation(i, board[i]) << " ";
    }
    std::cout << "\n\n";

}
// Converts to chess notation
std::string notation(int row, int col){
    std::string s;
    char c; 
    switch (col){ // detemines letter for the column number
        case 0:
            c = 'A';
            break;
        case 1:
            c = 'B';
            break;
        case 2:
            c = 'C';
            break;
        case 3:
            c = 'D';
            break;
        case 4:
            c = 'E';
            break;
        case 5:
            c = 'F';
            break;
        case 6:
            c = 'G';
            break;
        case 7:
            c = 'H';
            break;
        case 8:
            c = 'I';
            break;
        case 9:
            c = 'J';
            break;
        case 10:
            c = 'K';
            break;
        case 11:
            c = 'L';
            break;
        case 12:
            c = 'M';
            break;   
        case 13:
            c = 'N';
            break;
    }
    s = "[" + std::to_string(row + 1) + ", " + c + "]";
    // adds (row + 1) because chess noation is 1-14 and the rows is 0-13
    return s;
}

